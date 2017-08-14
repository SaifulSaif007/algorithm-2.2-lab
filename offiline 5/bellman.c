#include <stdio.h>

#define SIZE 30
#define MAX 99999

int cost[SIZE][3], d[SIZE] = {0}, pi[SIZE];
int v, e, s;

void relax(int u, int v);
void Initialize_single_source();
int weight(int u, int v);
int BellmanFord();

int main()
{
    int i, possible;


    scanf("%d %d %d", &v, &e, &s);

    for (i = 1; i <= e; i++)
    {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }

    possible = BellmanFord();

    if(possible)
    {
        printf("\nDistance of the vertices :\n");

        for (i = 1; i<=v ; i++)
        {
            printf("%d ", d[i]);
        }
    }
    else
    {
        printf("\nNegative Weight Cycle detected..");
    }

    return 0;
}

int BellmanFord()
{
    int i, j;

    Initialize_single_source();

    for (i = 1; i<= v-1 ; i++)
    {
        for (j = 1; j<=e ; j++)
        {
            relax(cost[j][0], cost[j][1]);
        }
    }

    //check negative edge
    int u, v;
    for (i = 1; i<=e ; i++)
    {
        u = cost[i][0];
        v = cost[i][1];

        if( d[u] + weight(u, v)< d[v])
        {
            return 0;
        }
    }
    return 1;
}

void Initialize_single_source()
{
    int i;
    for (i = 1; i <= v; i++)
    {
        d[i] = MAX;
        pi[i] = -1;
    }

    d[s] = 0;
}

void relax(int u, int v)
{
    if (d[v] > d[u] + weight(u, v) )
    {
        d[v] = d[u] + weight(u, v);
        pi[v] = u;
    }
}

int weight(int u, int v)
{
    int i;
    for (i = 1; i <= e; i++)
    {
        if (cost[i][0] == u && cost[i][1] == v)
        {
            return cost[i][2];
        }
    }
}

/*
5
8
1
1 2 6
1 4 7
2 3 5
2 4 8
3 2 -2
3 5 2
4 3 -3
4 5 3
*/
