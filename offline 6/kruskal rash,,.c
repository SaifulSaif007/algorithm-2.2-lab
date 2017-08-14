#include <stdio.h>

#define SIZE 50

int vertex1[SIZE], vertex2[SIZE], cost[SIZE];
int P[SIZE], t[SIZE][SIZE];

void Sort(int n);
int Kruscal(int n);

void Union(int i, int j)
{
    P[i] = j;
}

int Find(int i)
{
    while(P[i] >= 0)
    {
        i = P[i];
    }

    return i;
}



int main()
{
    int edges, i, mincost;

    //freopen("inputKruskal.txt", "r", stdin);

   // printf("Enter number of edges :");
    scanf("%d", &edges);

   // printf("\nNow Enter the edges :");

    for (i = 1; i<=edges ; i++)
    {
        scanf("%d %d %d", &vertex1[i], &vertex2[i], &cost[i]);
    }

    Sort(edges);

    mincost = Kruscal(edges);

    printf("\nMinimum Cost is : %d", mincost);

    return 0;
}

void Sort(int n)
{
    int i, j;

    for (i = 1; i<=n ; i++)
    {
        for (j = i+1;j<=n ;j++ )
        {
            if(cost[i] > cost[j])
            {
                int temp;

                temp = cost[i];
                cost[i] = cost[j];
                cost[j] = temp;

                temp = vertex1[i];
                vertex1[i] = vertex1[j];
                vertex1[j] = temp;

                temp = vertex2[i];
                vertex2[i] = vertex2[j];
                vertex2[j] = temp;
            }
        }
    }

    printf("\n\nSorted Elements :\n");

    for (i = 1;i<=n ;i++ )
    {
        printf("%d %d %d\n", vertex1[i], vertex2[i], cost[i]);
    }
}

int Kruscal(int n)
{
    int i, mincost, temp;

    for (i = 1;i <=n ; i++ )
    {
        P[i] = -1;
    }

    i = 0;
    mincost = 0;
    int p = 1;

    int j, k;

    printf("\n\nMinimum Cost Spanning tree is :\n\n(Vertex-Vertex-Cost)\n\n");

    while(i < n-1)
    {
        j = Find(vertex1[p]);
        k = Find(vertex2[p]);

        if(j != k)
        {
            i = i+1;
            t[i][1] = vertex1[p];
            t[i][2] = vertex2[p];

            mincost = mincost + cost[p];

            printf("%d %d %d\n", vertex1[p], vertex2[p], cost[p]);

            Union(j, k);

            //temp = i;
        }

        p++;

        if(p >= n)
        {
            break;
        }
    }

    return mincost;
}
