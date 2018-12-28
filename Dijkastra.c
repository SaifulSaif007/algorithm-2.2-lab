#include <stdio.h>

#define SIZE 20
#define MAX 1000


int cost[SIZE][3], d[SIZE] = {0}, p[SIZE], min_arr[SIZE] = {0};
int v, e, s;


void relax(int u, int v);
void Initialize_single_source();
int Extract_Min();

int main()
{
    int i;

    scanf("%d %d %d", &v, &e, &s);

    for (i = 1; i <= e; i++)
    {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }

    Dijkstra();


    printf("\nDistance of the vertices :\n");

    for (i = 1; i<=v ; i++)
    {
        printf("%d ", d[i]);
    }
    return 0;
}

void Dijkstra()
{
    int i, l, j;

    for (i = 1; i <= v; i++)
    {
        d[i] = MAX;
        p[i] = -1;
    }

    d[s] = 0;

    for (i = 1; i <= v; i++)
    {
        l = Extract_Min();

        for (j = 1; j <= e; j++)
        {
            if (cost[j][0] == l)
                relax(l, cost[j][1]);
        }
    }
}

int Extract_Min()
{
    int c = 1000, j, i;

    for (i = 1; i <= v; i++)
        if (d[i] < c && !min_arr[i])
        {
            c = d[i];
            j = i;
        }

    min_arr[j] = 1;

    return j;
}





void relax(int u, int v)
{
    if (d[v] > d[u] + weight(u, v) )
    {
        d[v] = d[u] + weight(u, v);
        p[v] = u;
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
9
1
1 2 10
1 3 5
2 3 2
3 2 3
2 4 1
3 4 9
3 5 2
4 5 4
5 4 6

*/
