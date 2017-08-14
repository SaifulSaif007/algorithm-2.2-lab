#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<conio.h>

int n,p,r;
int array[200];

int main()
{
    printf("num");
    scanf("%d",&n);
    random(n);
    merge(array,1,n);
    print();
    return 0;
}

void random(int n)
{
    int i;
    for(i=1;i<=n;i++){
        array[i] = rand()%100+5;
        printf("%d ",array[i]);
    }
}
merge(int array[],int p,int r)
{
    if(p<r){
    int q = floor((p+r)/2);
    merge(array,p,q);
    merge(array,q+1,r);
    merge_sort(array,p,q,r);
    }
}

merge_sort(int array[],int p,int q,int r)
{
    int n1 = q-p+1;
    int n2 = r-q;

    int R[100] , L[100];
    int i,j,k;
    for(i=1;i<=n1;i++){
        L[i] = array[p+i-1];
    }

    for(j=1;j<=n2;j++){
        R[j] = array[q+j];
    }

    L[n1+1] = INT_MAX;
    R[n2+1] = INT_MAX;

    i=1;
    j=1;
    for(k=p;k<=r;k++){

        if(L[i]<R[j])
            {array[k] = L[i];
        i++;}
        else{
            array[k] = R[j];
            j++;
        }
    }
}

void print()
{
    int i;
    for(i=1;i<=n;i++)
        printf("  %d",array[i]);
}
