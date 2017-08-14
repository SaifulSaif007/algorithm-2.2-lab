#include<stdio.h>

int array[10][10],visited[10],n,cost=0;


int main()
{

    int i,j;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	printf("Enter cost in matrix\n");
	for( i=0;i <n ;i++)
	{
		for( j=0;j < n;j++)
			scanf("%d",&array[i][j]);
            visited[i]=0;
	}

	printf("\nTraveling path is :");

	mincost(0);

    printf("\nMinimum cost:%d",cost);

    return 0;
}



void mincost(int m)
{
	int i,node;
	visited[m]=1;
	printf("%d -->",m+1);
	node=least(m);
	if(node==999)
	{
		node=0;
		printf("%d",node+1);
		cost+=array[m][node];
		return;
	}
	mincost(node);
}

int least(int c)
{
	int i,mx=999;
	int min=999,kmin;
	for(i=0;i < n;i++)
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

