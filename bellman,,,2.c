
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define INFINITY 999999

int bellman_ford(int);
void initialize_single_source();
void relax(int,int,int);
void final();

typedef struct
{
     int u, v, w;
    char label[10];
} Edge;

int n; // the number of nodes //
int e; // the number of edges //
Edge edges[1024];
int d[32];

int main()
{
    int i, j;
    int w;
    char lbl[10];
    clrscr();
    printf("\nB E L L M A N  F O R D  A L G O R I T M");
    printf("\n- - - - - - -  - - - -  - - - - - - - -");
    printf("\nEnter the number of nodes : ");
    scanf("%d",&n);
    printf("\nPlease label the nodes ");
    for(i = 0; i < n; i++)
    {
        scanf("%s",&lbl);
        strcpy(edges[i].label,lbl);
    }
    e = 0;
    printf("\nEnter the weights of edges : ");
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
        {
            printf("\nEnter the weight of %s to %s :",edges[i].label,edges[j].label);
            scanf("%d",&w);
            if (w != 0)
            {
                edges[e].u = i;
                edges[e].v = j;
                edges[e].w = w;
                ++e;
            }
        }
    bellman_ford(0);
    final();
    return 0;
}

int bellman_ford(int s)
{
    int i,j;
    initialize_single_source(s);

    for(i=1; i
        for(j=1; j
        {
            relax(edges[j].u,edges[j].v,edges[j].w);
        }
    for(i=0; i
        for(j=0; j
        {
            if(d[edges[j].v]>d[edges[j].u]+edges[j].w)
            {
                printf("Error");
                exit(1);
            }
        }
    return 0;
}

void initialize_single_source(int s)
{
    int i;
    for (i=0; i
    {
        d[i]=INFINITY;
    }
    d[s]=0;
}

void relax(int U_tmp,int V_tmp,int W_tmp)
{
    if(d[V_tmp]>d[U_tmp]+W_tmp)
    {
        d[V_tmp]=d[U_tmp]+W_tmp;
    }
}

void final()
{
    int i;

    printf("Distances:\n");

    for (i = 0; i < n; i++)
        printf("to %s\t", edges[i].label);
    printf("\n");

    for (i = 0; i < n; i++)
        printf("%d\t", d[i]);

    printf("\n\n");
}
