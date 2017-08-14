#include<stdio.h>
#include<stdlib.h>

int a[10][10],list[20],stack[20],ind[20],s,k=0,top=-1,n;

void topsort(int n,int a[10][10])
{
   int i,j;
for(i=1;i<=n;i++)
{
   s=0;
    for(j=1;j<=n;j++)
{
   s =s+a[j][i];
}
   ind[i]=s;
 }

   for(i=1;i<=n;i++)
   {
   if(ind[i]==0)
   stack[++top]=i;
  }
    while(top!=-1)
    {
    i=stack[top--];
    list[k++]=i;
    for(j=1;j<=n;j++)
    {
    if(a[i][j]==1)
    {
    ind[j]--;
    if(ind[j]==0)
    stack[++top]=j;
     }
  }
 }
}

void Input()
    {
    int i,j,v1,v2,e;
    printf("Enter the no of vertiices\n");
    scanf("%d",&n);
    printf("Enter number of edge...\n");
    scanf("%d",&e);

    printf("Enter directed vertex....\n");
    for(i=1;i<=e;i++){
    scanf("%d%d",&v1,&v2);
    a[v1][v2]=1;
    }
}

    int main()
{
    int i,flag=1;
    Input();
    topsort(n,a);
    for(i=0;i<n;i++)
    {
    if(list[i]==0)
    flag=0;
    }
    if(flag==1)
    {
    printf("Topological sorted vertices are\n");
    for(i=0;i<n;i++)
    printf("%d\n",list[i]);
    }
    else
    printf("Topological sorting is not possible\n");


    return (0);
}
