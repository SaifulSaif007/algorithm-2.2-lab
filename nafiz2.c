#include<stdio.h>

#include<limits.h>



long int n;
long int arr1[100000];
long int arr2[100000];
long int t1,t2, Time;
long int move = 0;
long int comp = 0;

void ini_random_number();

void bubble_sort();

void insertion_sort();

void selection_sort();

int main()
{

   printf("How many numbers do u want? : ");
   scanf("%d",&n);

   ini_random_number();
   bubble_sort();
   insertion_sort();
   selection_sort();


   //getch();
   return 0;

}
void bubble_sort()
{
  int k,i,j,t,x;
  comp = 0, move = 0;
  for(i=0;i<n;i++)
    {
    arr2[i] = arr1[i];
     }
     comp = 0, move = 0;
    k=n;
    t1 = clock();


  while(k!=0)
  {
    t=0;
    for(j=1;j<= k-1;j++)
    {
        comp++;
      if(arr2[j]>arr2[j+1])
      {
        x=arr2[j];
        arr2[j]=arr2[j+1];
        arr2[j+1]=x;
        t=j;
        move++;
      }
    }
    k=t;
  }
   t2 = clock();
    Time = t2-t1;
    printf("Bubble sort:\t");
    printf("%d ms\t",Time);
    printf("comp: %d\t",comp);
    printf("move: %d\n",move);
}
void insertion_sort()
{
  int i,j,t,x;
  comp = 0, move = 0;
  for(i=1;i<=n;i++)
    {
    arr2[i] = arr1[i];
     }
    arr2[0] = INT_MIN;
    t1 = clock();
    for(j=2; j<=n; j++){
        comp++;
        i = j-1;
        t = arr2[j];
        while(t<arr2[i]){
            arr2[i+1] = arr2[i];
            i = i-1;
            move++;
    }
            arr2[i+1] = t;
        }
    t2 =clock();
	Time = t2-t1;
	printf("Insertion Sort:\t");
	printf("%d ms\t",Time);
	printf("comp: %d\t",comp);
    printf("move :%d\t",move);
    printf("\n");
    }

void selection_sort()
{
  int i,j,temp,k,x;
  comp = 0, move = 0;
  for(i=1;i<=n;i++)
    {
    arr2[i] = arr1[i];
     }
    arr2[0] = INT_MIN;

     t1 = clock();
    for(j=n; j>=2; j--){
        comp++;
        temp = 1;
        for(k = 2; k<=j; k++){
            if(arr2[temp]<arr2[k]){
            temp = k;
            move++;
        }
        x = arr2[j];
        arr2[j] = arr2[temp];
        arr2[temp] = x;
    }
}
    t2 = clock();
    Time = t2-t1;
    printf("Selection Sort:\t");
    printf("%d ms\t",Time);
    printf("comp: %d\t",comp);
    printf("move: %d\n",move);
}



void ini_random_number()
{
   int i;
   //randomize();
   //printf("\n\nRandom numbers are :\n\n ");

   for(i=1;i<=n;i++)
   {
      arr1[i]=rand()%10000;

   }
   arr1[0]=INT_MIN;
}





