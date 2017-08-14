#include<stdio.h>
#include<limits.h>

void input();
void MERGE_SORT(int A[],int p,int r);
void MERGE(int A[],int p,int q,int r);
void result();
int A[100];
int n;
void input()
{
    int i;
    printf("How many numbers : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("A[%d] = ",i);
        scanf("%d",&A[i]);
    }
}

void MERGE(int A[],int p,int q,int r)
{
    int i,j,k;
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1];
    int R[n2+1];
    for(i=1;i<=n1;i++)
    {
        L[i] = A[p+i-1];
    }
    for(j=1;j<=n2;j++)
    {
        R[j] = A[q+j];
    }
    L[n1+1] = INT_MAX;
    R[n2+1] = INT_MAX;
    i = 1;
    j = 1;
    for(k = p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            A[k] = L[i];
            i = i+1;
        }
        else
        {
            A[k] = R[j];
            j = j+1;
        }
    }
}

void MERGE_SORT(int A[],int p,int r)
{
    int q;
    if (p<r)

    {
        q = floor((p+r)/2);
        MERGE_SORT(A,p,q);
        MERGE_SORT(A,q+1,r);
        MERGE(A,p,q,r);
    }
}


void result()
{

    int i;
    printf("The sorted list of the given number is:\n");
    for(i=1;i<=n;i++)
    {
        printf("A[%d] = %d\n",i,A[i]);
    }
}

int main()
{
    input();
    MERGE_SORT(A,1,n);
    result();
    return 0;
}
