#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<conio.h>

long int n,p,r;
int arr[100];

void random_number();
void merge_sort(int [],int ,int);
void merge(int[],int ,int ,int);
void print();

int main()
{
    printf("How many numbers to be sorted....?\n\n");
    scanf("%d",&n);

    random_number();
    merge_sort(arr,1,n);

    print();
    getch();
    return 0;
}

void random_number()
{
    int i;
    printf("\n\n The random numbers are: \n\n");

    for(i=1;i<=n;i++){
        arr[i] = rand()%1000;
        printf("  %d\t",arr[i]);
    }

    arr[0] = INT_MIN;
}


void merge_sort(int arr[],int p,int r)
{
    if(p<r){

        int q = floor((p+r)/2);
        merge_sort(arr,p,q);
        merge_sort(arr,q+1,r);
        merge(arr,p,q,r);

    }

}

void merge(int arr[],int p,int q,int r)
{

    int n1 = q-p+1;
    int n2 = r-q;

    int L[100],R[100];
    int i,j,k;

    for(i=1;i<=n1;i++){
        L[i] = arr[p+i-1];
    }

    for(j=1;j<=n2;j++){
        R[j] = arr[q+j];
    }

    L[n1+1] = INT_MAX;
    R[n2+1] = INT_MAX;

    i = 1;
    j = 1;

    for(k = p; k<=r; k++)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i = i+1;
        }
        else
        {
            arr[k] = R[j];
            j = j+1;
        }
    }

}

void print()
{
    int i;

    printf("\n\n After sorting the numbers are: \n\n");
    for(i=1;i<=n;i++){
        printf("  %d\t",arr[i]);
    }

}

