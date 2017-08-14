#include<stdio.h>

 int n;
 int arr1[2000000];
 int arr[2000000];
 int t1,t2,T;
 int comp;
 int move;

void input(){
    int i;
    printf("How many numbers to be sorted: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
    arr1[i] = rand()%1000;
    }
}

void Bubble_sort(){

    int k,j,t,x,i;
    for(i=0;i<n;i++)
    {
    arr[i] = arr1[i];
     }
    comp = 0, move = 0;
    k=n;
    t1 = clock();
    while(k!=0)
  {
    t=0;
    for(j=1;j<=k-1;j++)
    {
        comp++;
      if(arr[j]>arr[j+1])
      {
        x=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=x;
        t=j;
        move++;
      }
    }
        k=t;
  }
    t2 = clock();
    T = t2-t1;
    printf("Bubble Sort:\t");
    printf("%d ms\t",T);
    printf("comp: %d\t",comp);
    printf("move: %d\n",move);
}


    void insertion_sort()
{
    int t, i, j;
    comp = 0, move = 0;
    for(i=0;i<n;i++)
     {
       arr[i] = arr1[i];
     }

    t1 = clock();
	for (j = 2; j<=n ; j++)
	{
	    comp++;
		i = j - 1;
		t = arr[j];
		while (t < arr[i])
		{
			arr[i + 1] = arr[i];
			i = i - 1;
			move++;
		}
		arr[i + 1] = t;
	}
	t2 =clock();
	T = t2-t1;
	printf("Insertion Sort:\t");
	printf("%d ms\t",T);
	printf("comp: %d\t",comp);
    printf("move :%d\n",move);
}
    void Selection_sort()
{
    int j,t,k,x,i;
    comp = 0, move = 0;
    for(i=0;i<n;i++)
     {
       arr[i] = arr1[i];
     }
    t1 = clock();
    for(j=n; j>=2; j--){
        comp++;
        t = 1;
        for(k=2; k<=j; k++){
            if(arr[t] < arr[k]){
            t = k;
            move++;
            }
        }
        x = arr[j];
        arr[j] = arr[t];
        arr[t] = x;
    }
    t2 = clock();
    T = t2-t1;
    printf("Selection Sort:\t");
    printf("%d ms\t",T);
    printf("comp: %d\t",comp);
    printf("move: %d\n",move);
}



int main()
{

    input();
    Bubble_sort();
    insertion_sort();
    Selection_sort();

    return 0;
}
