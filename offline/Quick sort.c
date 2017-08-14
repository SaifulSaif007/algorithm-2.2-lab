#include<stdio.h>
#include<conio.h>
#include<limits.h>
#include<stdlib.h>

long int n;
long int arr[100];

void random_number();
void quick_sort(int ,int );
void print();

int main()
{
    printf("How many numbers do you want to sort....?\n\n");
    scanf("%d",&n);
    random_number();
    quick_sort(1,n);
    print();
    getch();
    return 0;
}

void quick_sort(int f,int l)
{
    int i,j,temp;

    if(f<l){

        i = f + 1;
        j = l;


        while(arr[i]<arr[f]){
                i = i+1;
            }

        while(arr[j]>arr[f]){
                j = j - 1;
            }

         while(i<j){

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        while(arr[i]<=arr[f]){
            i = i+1;
        }
         while(arr[j]>arr[f]){
            j = j-1;
        }
    }


            temp = arr[f];
            arr[f] = arr[j];
            arr[j] = temp;


            quick_sort(f,j-1);
            quick_sort(j+1,l);
    }

}

void random_number(){

    int i;

    printf("\n\n randoms  numbers are:\n\n");

     for(i=1;i<=n;i++)
   {
      arr[i]=rand()%1000;
      printf("\t%d  ",arr[i]);
   }
   arr[0]=INT_MIN;

}

void print()
{
    int i;
    printf("\n\n After  Sorting :\n\n ");

   for(i=1;i<=n;  i++)
   {
      printf("\t%d",arr[i]);
   }
}

