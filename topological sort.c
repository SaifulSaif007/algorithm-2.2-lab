#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 200

int n,adj[MAX][MAX];
int front = -1,rear = -1,queue[MAX],del_item;

void main()
{
    int i,j = 0,k;
	int topsort[MAX],indeg[MAX];
	create_graph();



}

create_graph() {
	int i,max_edges,origin,destin;
	printf("\n Enter number of vertices:");
	scanf("%d",&n);
    printf("Enter the number of edge...");
    scanf("%d",&max_edges);
	for (i = 1;i <= max_edges;i++) {
		//printf("\n Enter edge %d (00 to quit):",i);
		scanf("%d%d",&origin,&destin);
		if((origin == 0) && (destin == 0)) {
			printf("Invalid edge!!\n");
			i--;
		} else
		   adj[origin][destin] = 1;
	}
	return;
}
