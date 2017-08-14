#include<stdio.h>

int p[20], m[20][20];

int main()
{
    int i,j,size,value;
    printf("enter the size of matrix:");
    scanf("%d",&size);
    printf("Enter the dimensions");
    for(i=0;i<=size;i++)
        scanf("%d",&p[i]);

    value = chain(1,size);
    printf("the value: %d",value);
    printf("the optimal order..");
    optimal(1,size);
    return 0;
}

    int chain(int i,int j)
    {
        if(j==1)
            return;
        int k,count;
        int min = 99999;
        for(k=1;k<=j;k++){
            count = chain(i,k) + chain(k+1,i) + p[i-1]*p[k]*p[j];
            if(count<min)
            {
                min = count;
                m[i][j] = k;
            }
        }
        return min;
    }

    void optimal(int i,int j)
    {

        if(i==j)
            printf("M%d",i);
        else
            printf("(");
        optimal(i,m[i][j]);
        optimal(m[i][j]+1,j);
        printf("(");
    }

