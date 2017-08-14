#include<stdio.h>
#include<conio.h>
int sum=0;
int max(int a,int b)
{
  if(a>b)
 return a;
   else
 return b;
}

void knapsack(int m,int n,int w[],int b[])
{
  int v[100][200],x[10],i,j;
  for(i=0;i<=m;i++)
  v[0][i]=0;
  for(i=1;i<=n;i++)
 {
 for(j=0;j<=m;j++)
 {
 if(j>=w[i])
 v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+b[i]);
 else
 v[i][j]=v[i-1][j];
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
printf("\nthe optimal weight:\n");
for(i=1;i<=n;i++)
{
if(x[i]==1)
{
printf("X%d=1\t",i);
sum=sum+b[i];
}
else
printf("X%d=0\t",i);
}
printf("\nTotal profit = %d",sum);
}

  int main()
{
int w[10],b[10],i,m,n;

printf("enter the number of items..: ");
scanf("%d",&n);

  printf("Enter weights and benefits:\n");
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        scanf("%d",&b[i]);
    }

printf("the capacity of knapsack :");
scanf("%d",&m);
knapsack(m,n,w,b);

return 0;
}
