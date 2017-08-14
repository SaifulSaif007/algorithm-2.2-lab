#include<stdio.h>
#include<stdlib.h>

int a,b,u,v,n,i,j,ne=1;
int visited[20], cost[20][20], min, mincost = 0;

int main()
{
    printf("node:");
    scanf("%d",&n);
    printf("matrix form");

    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
        scanf("%d",&cost[i][j]);
        if(cost[i][j]==0)
           cost[i][j]=999;
    }

    visited[1] = 1;
    while(ne<n){

        for(i=1,min=999;i<=n;i++)
            for(j=1;j<=n;j++)
            if(cost[i][j] < min)
        if(visited[i]!=0){
            min = cost[i][j];
            a=u=i;
            b=v=j;
            }

       if(visited[u] || visited[v]){
        printf("Edge %d (%d %d) cost %d\n",ne++,a,b,min);
        mincost = mincost + min;
        visited[b] = 1;
       }
       cost[a][b] = cost[b][a] = 999;
    }
printf("\ncost %d",mincost);
    return 0;
}
