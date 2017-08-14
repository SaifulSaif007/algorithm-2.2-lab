#include<stdio.h>
#include<stdlib.h>

int a[10][10],list[20],stack[20],ind[20],s,k=0,top=-1,n;

void Input()
{
   int i,j,k,v1,v2,e;
     printf("Enter the no of vertex : ");
    scanf("%d",&n);
    printf("Enter number of edge:  ");
    scanf("%d",&e);

    printf("Enter directed vertex");
    for(i=1;i<=e;i++){
    scanf("%d %d",&v1,&v2);
    a[v1][v2]= 1;
    }
}

    int main()
{
    int i,j,k;
    int flag=1;

    Input();
    topsort();

    for(i=0;i<n;i++)
    {
    if(list[i]==0)
    flag=0;
    }
    if(flag==1)
    {
   printf("after topsort...\n");
    for(i=0;i<n;i++)
   printf("%d\n",list[i]);
}
    else
    printf("Topological sorting is not possible..");


    return (0);
}



void topsort()
{
   int i,j;
   for(i=1;i<=n;i++)
 {
   s = 0;

    for(j=1;j<=n;j++)
{
   s = s + a[j][i];
}
    ind[i] = s;
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

