#include<stdio.h>

int array[20][20],visited[20],n,cost=0;

int main()
{
    int i,j;
    printf("enter the number of nodes..");
    scanf("%d",&n);
    printf("enter the cost matrix:\n");

    for(i=0;i<n;i++)
    for(j=0;j<n;j++){
        scanf("%d",&array[i][j]);
        visited[i] = 0;
    }

    mincost(0);
    printf("\nthe cost: %d",cost);
    return 0;
}

void mincost(int m)
{
    int i,node;
    visited[m] = 1;
    printf("%d->",m+1);
    node = least(m);

    if(node == 999){
        node = 0;
        printf("%d",node+1);
        cost +=array[m][node];
    return;
    }

    mincost(node);

}

int least(int c)
{
	int i,mx=999;
	int min=999,kmin;
	for(i=0;i <n;i++)
	{
		if((array[c][i]!=0)&&(visited[i]==0))
			if(array[c][i] < min)
			{
				min=array[i][c]+array[c][i];
				kmin=array[c][i];
				mx=i;
			}
	}
	if(min!=999)
		cost+=kmin;
	return mx;
}
