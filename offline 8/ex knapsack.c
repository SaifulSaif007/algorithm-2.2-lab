#include<stdio.h>
int sum = 0;

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    int w[20], b[20], i ,j,n,m;
    printf("Enter the no of items: ");
    scanf("%d",&n);

    printf("Enter the weight and benefits\n");
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        scanf("%d",&b[i]);
    }
    printf("enter the capacity of knapsack\n");
    scanf("%d",&m);
    knapsack(n,m,w,b);

    return 0;
}

void knapsack(int n,int m,int w[],int b[])
{
    int v[20][20], x[20],i,j;
    for(i=0;i<=m;i++){
        v[0][i] = 0;
    }
    for(i=1;i<=n;i++){
        for(j=0;j<=m;j++){
            if(j>=w[i]){
                v[i][j] = max(v[i-1][j], v[i-1][j-w[i]]+b[i]);
            }
            else
                v[i][j] = v[i-1][j];
        }
    }

    for(i=1;i<=n;i++){
    x[i]=0;
    }
    i=n;
    j=m;
 while(i>0 && j>0)
{
    if(v[i][j]!=v[i-1][j])
 {
    x[i]=1;
    j=j-w[i];
    }
    i--;
}
printf("the optimal weight..\n");

for(i=1;i<=n;i++){
    if(x[i]==1){
            printf("\tX%d",x[i]);
        sum = sum + b[i];
    }
    else
    printf("\tX%d",x[i]);
}
printf("\ntotal benefit : %d",sum);


}
