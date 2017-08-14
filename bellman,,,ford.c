#include<stdio.h>
#include<stdlib.h>

int G[20][20], edge[20][2], V, S, dis[20];

int main()
{
    int i,j;
    int E=0;
    printf("Enter the vertex:");
    scanf("%d",&V);
    printf("enter matrix form\n");
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
    {
        scanf("%d", &G[i][j]);
        if(G[i][j]!=0)
            edge[E][0]=i, edge[E++][1]=j;

    }

    if(Bellman(E))
        printf("no negative...");
    else
        printf("negative");

    return 0;
}

int Bellman(int E)

{
    int i,j,k,u,v,flag = 1;
    for(i=0;i<V;i++){
        dis[i] = 1000;
        }
    printf("enter source:");
    scanf("%d",&S);
    dis[S-1] = 0;

    for(i=0;i<V-1;i++)
    {
        for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(dis[u]+G[u][v] < dis[v])
                dis[v] = dis[u] + G[u][v] ;
        }
    }
    for(k=0;k<E;k++)
    {
        u = edge[k][0] , v= edge[k][1];
        if(dis[u]+ G[u][v] < dis[v])
            flag = 0;
    }

    if(flag)
    {
        for(j=0;j<V;j++)
        printf("%d",dis[i]);
    }

    return flag;


}
