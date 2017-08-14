#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define Max 999

int min,mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
void main()
{
    int i,j,k,a,b,u,v,n,ne=1;
    printf("Enter the no. of Vertex:\n");
    scanf("%d",&n);
    printf("Enter the Cost of Adjacency Matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=Max;
        }
    }
    printf("\nThe Edges of Minimum Cost Spanning Tree are->\n");
    while(ne<n)
    {
        for(i=1,min=Max;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            printf("\n%d edge (%d,%d) =%d",ne++,a,b,min);
            mincost +=min;
        }
        cost[a][b]=cost[b][a]=Max;
    }
    printf("\n\nMinimum Cost = %d\n",mincost);
}

int find(int i)
{
    while(parent[i])
    i=parent[i];
    return i;
}

int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}


/*4
0 1 0 0
1 0 2 3
0 2 0 4
0 3 4 0
*/
