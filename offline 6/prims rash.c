#include<stdio.h>

int n, cost[10][10];
int near[10], tree[10][4];

void prims();

void main()
{
    int i,j;

    //freopen("inputPrims.txt", "r", stdin);

   // printf("\n Enter the no. of vertices:- ");
    scanf("%d", &n);

   // printf ("\n Enter the costs of edges in matrix form: ");

    for(i=1; i<= n; i++)
        for(j=1; j<= n; j++)
            scanf("%d",&cost[i][j]);

    printf("\nThe matrix is:\n");
    for(i=1; i<= n; i++)
    {
        for(j=1; j<= n; j++)
            printf("%d\t",cost[i][j]);

        printf("\n");
    }

    prims();

}


void prims()
{
    int i, j, k, l,x;
    int temp,mincost=0;

    /* For first smallest edge */
    temp=cost[1][1];

    for(i=1; i<= n; i++)
    {
        for(j=1; j<= n; j++)
        {
            if(temp>cost[i][j])
            {
                temp=cost[i][j];
                k=i;
                l=j;
            }
        }
    }
    /* Now we have fist smallest edge in graph */
    tree[1][1]=k;
    tree[1][2]=l;
    tree[1][3]=temp;

    mincost=temp;

    /* Now we have to find min dis of each
    vertex from either k or l
    by initialising near[] array
    */

    for(i=1; i<= n; i++)
    {
        if(cost[i][k]< cost[i][l])
            near[i]=k;
        else
            near[i]=l;
    }
    /* To indicate visited vertex, initialise near[] for them to 0 */
    near[k]=0;
    near[l]=0;

    /* Now find out remaining n-2 edges */
    temp=999;

    for(i=2; i<= n-1; i++)
    {
        for(j=1; j<= n; j++)
        {
            if(near[j]!=0 && cost[j][near[j]] < temp)
            {
                temp=cost[j][near[j]];
                x=j;
            }
        }

        /* Now we got next vertex */
        tree[i][1]=x;
        tree[i][2]=near[x];
        tree[i][3]=cost[x][near[x]];

        mincost=mincost+cost[x][near[x]];

        near[x]=0;

        /* Now find if x is nearest to any vertex
        than its previous near value */

        for(j=1; j<= n; j++)
        {
            if(near[j]!=0 && cost[j][near[j]] > cost[j][x])
                near[j]=x;
        }
        temp=999;
    }
    /* Now we have the answer, just going to print it */
    printf("\n\nThe Minimum Spanning tree is:\n\nVertex\tVertex\tCost\n");

    for(i=1; i<= n-1; i++)//n-1 ta edge for n vertex
    {
        for(j=1; j<= 3; j++)
            printf("%d\t", tree[i][j]);

        printf("\n");
    }

    printf("\n Minimum cost : %d", mincost);
}
