
#include <stdio.h>

int arr[100][100];

int colour[100],v;
void dfs(int n)
{
    int i ;
    printf("\nNode: %d",n);
    colour[n]=1;
    for(i=1;i<=v;i++)
        {
            if(arr[n][i]==1&&colour[i]==0)
                dfs(i);
        }
}


int main(void)
{
    int i, j,k;

    printf("Enter number of vertices : ");
    scanf("%d",&v);
      printf("ENter graph in matrix form ");

    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){

        scanf("%d",&arr[i][j]);
        }
    }

    printf("Enter the starting node : ");
    scanf("%d",&k);


    for(i=1;i<=v;i++)
        colour[i]=0;

    for(i=1;i<=v;i++)
        if(colour[i]==0)
            dfs(i);
}
