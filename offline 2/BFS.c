#include<stdio.h>
#include<conio.h>
int a[20][20],q[20],visited[20],n,i,j,f,r;
void bfs(int v) {

    f=r=-1;
	printf("%d ",v);
	visited[v] = 1;
	r++;
	f++;
	q[r] = v;
	while(f<=r){
        v = q[f];
        f++;
        for(i=1;i<=n;i++){
            if(a[v][i] && !visited[i]){
                printf("%d ",i);
                visited[i] = 1;
                r++;
                q[r] = i;
                }
         }
	}
}
void main() {
	int v;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		q[i]=0;
		visited[i]=0;
	}
	printf("\n Enter graph data in matrix form:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	    scanf("%d",&a[i][j]);

	printf("\n Enter the starting vertex:");

	scanf("%d",&v);

	for (i=1;i<=n;i++)
    {
     bfs(v);
     }
}
