#include <stdio.h>
int arr[100][100], color[100], Q[100], v, top=1;

void bfs(int n)
{
    int i, j, k;
    color[n]=1;
    Q[top]=n;
    while(top>0)
    {
        k = Q[1];
        printf("\nNode: %d",k);
        for(j=1;j<top;j++)
            Q[j]=Q[j+1];
        top--;
        for(i=1;i<=v;i++)
        {
            if(arr[k][i]==1&&color[i]==0)
            {
                color[i]=1;
                top++;
                Q[top]=i;
            }
        }
        color[k]=1;
    }
}

int main(void)
{
    int i, j, k, s;
    printf("Enter number of vertices : ");
    scanf("%d",&v);
    printf("Enter graph in matrix form\n");

    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
            scanf("%d",&arr[i][j]);
    }
    printf("Enter the starting node : ");
    scanf("%d",&s);
    for(i=1;i<=v;i++)
        color[i]=0;
    bfs(s);
    return 0;
}
