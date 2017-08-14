#include<stdio.h>

int a,b,u,v,i,j,n,ne=1;
int visited[20]={0},min,mincost=0, cost[20][20];

int main()
{
    scanf("%d",&n);
    printf("matrix...\n");

    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        scanf("%d",&cost[i][j]);
        if(cost[i][j]==0){
            cost[i][j]=99999;
        }
    }

    visited[1] = 1;
    printf("\n");

    while(ne<n)
    {
        for(i=1;i<=n;i++){
                min = 99999;
        for(j=1;j<=n;j++)
        {
          if(cost[i][j]<min){
              if(visited[i]!=0){
                    min = cost[i][j];
                    a=u=i;
                    b=v=j;
            }
        }
    }

        if(visited[u]==0 || visited[v]==0){
            printf("%d edge (%d %d) cost %d\n",ne++,a,b,min);
            mincost = mincost + min;
               visited[b] = 1;
        }
      cost[a][b] = cost[b][a] = 99999;

        }
    }

    printf("\nmincost %d",mincost);
}
