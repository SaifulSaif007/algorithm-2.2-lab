#include<stdio.h>

int n;
int dist[20][20];


int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&dist[i][j]);

    floyd_warshall();
    return 0;
}

void floyd_warshall()
{
    int i,j,k;
    for(k=0;k<n;k++){
        printDist();
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if((dist[i][k]* dist[k][j] !=0) && (i !=j))
        if(dist[i][k] + dist[k][j] <dist[i][j])
        dist[i][j] = dist[i][k] + dist[k][j];
    }
    printDist();
}


void printDist()

{
    int i,j,k;
    printf("    ");
    for(i=0;i<n;i++){
        printf("%4c",'A'+i);
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("%4c",'A'+i);
    for(j=0;j<n;j++){
        printf("%4d",dist[i][j]);}
        printf("\n");
    }
    printf("\n");
}
