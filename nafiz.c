#include<stdio.h>

#include<limits.h>



long int n;
long int arr[100];

void ini_random_number();
void print_bubble();
void bubble_sort();
void print_insertion();
void insertion_sort();
void print_selection();
void selection_sort();

int main()
{

   printf("How many numbers do u want? : ");
   scanf("%d",&n);

   ini_random_number();
   bubble_sort();
   print_bubble();
   insertion_sort();
   print_insertion();
   selection_sort();
   print_selection();

   getch();
   return 0;

}
void bubble_sort()
{
  int k,j,t,x;
  k=n;

  while(k!=0)
  {
    t=0;
    for(j=1;j<= k-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
        x=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=x;
        t=j;
      }
    }
    k=t;
  }
}
void insertion_sort()
{
  int i,j,t,x;
    arr[0] = INT_MIN;
    for(j=2; j<=n; j++){
        i = j-1;
        t = arr [j];
        while(t<arr[i]){
            arr[i+1] = arr[i];
            i = i-1;
            arr[i+1] = t;
        }
    }
}
void selection_sort()
{
  int i,j,temp,k,x;
    //arr[0] = INT_MIN;

    for(j=n; j>=2; j--){
        temp = 1;
        for(k = 2; k<=j; k++){
            if(arr[temp]<arr[k]){
            temp = k;
        }
        x = arr[j];
        arr[j] = arr[temp];
        arr[temp] = x;
    }
}
}

void ini_random_number()
{
   int i;
   //randomize();
   printf("\n\nRandom numbers are :\n\n ");

   for(i=1;i<=n;i++)
   {
      arr[i]=rand()%1000;
      printf(" %d ",arr[i]);
   }
   arr[0]=INT_MIN;
}
void print_bubble()
{
   int i,j;
   printf("\n\nAfter Bubble Sorting :\n\n ");
   for(j=1;j<=n;  j++)
   {
      printf(" %d ",arr[j]);
   }
     printf("\n");

}
void print_insertion()
{
   int i,j;
   printf("\n\nAfter insertion Sorting :\n\n ");
   for(j=1;j<=n;  j++)
   {
      printf(" %d ",arr[j]);
   }
     printf("\n");

}
void print_selection()
{
   int i,j;
   printf("\n\nAfter selection Sorting :\n\n ");
   for(j=1;j<=n;  j++)
   {
      printf(" %d ",arr[j]);
   }
     printf("\n");

}


