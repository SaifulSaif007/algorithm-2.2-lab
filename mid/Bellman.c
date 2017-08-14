 #include<stdio.h>
 #include<stdlib.h>

 int main()
{
int V,edge[20][2],G[20][20],i,j,E=0;
    printf("Enter no. of vertex: ");
    scanf("%d",&V);

printf("Enter graph in matrix form:\n");
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
        {
        scanf("%d",&G[i][j]);
     if(G[i][j]!=0)
     edge[E][0]=i,edge[E++][1]=j;
        }

    if(Bellman_Ford(G,V,E,edge))
        printf("\nNo negative weight cycle\n");
    else printf("\nNegative weight cycle exists\n");
    return 0;
}



int Bellman_Ford(int G[20][20] , int V, int E, int edge[20][2])
{
    int i,u,v,k,dis[20],S,flag=1;
     for(i=0;i<V;i++)
    dis[i] = 1000 ;
    printf("Enter source: ");
        scanf("%d",&S);
        dis[S-1]=0 ;
    for(i=0;i<V-1;i++)
    {
        for(k=0;k<E;k++)
        {
        u = edge[k][0] , v = edge[k][1] ;
        if(dis[u] + G[u][v] < dis[v])
            dis[v] = dis[u] + G[u][v] ;
        }
    }

 for(i=0;i<V-1;i++){
 for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(dis[u]+G[u][v] < dis[v])
                flag = 0 ;
        }
 }
        if(flag)
            for(i=0;i<V;i++)
                printf("Vertex %d -> cost = %d \n",i+1,dis[i]);

        return flag;
}








