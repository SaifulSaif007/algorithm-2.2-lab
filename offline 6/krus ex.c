#include<stdio.h>

int a,b,i,j,u,v,n,ne=1;
int cost[20][20],parent[20],min,mincost=0;

int main()
{
    scanf("%d",&n);
    printf("matrix");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
        scanf("%d",&cost[i][j]);
        if(cost[i][j]==0){
            cost[i][j] = 999;
        }
}

while(ne<n){

    for(i=1,min=999;i<=n;i++){
        for(j=1;j<=n;j++){
            if(cost[i][j]<min){
                min = cost[i][j];
                a=u=i;
                b=v=j;
            }
        }
    }
    u = find(u);
    v = find(v);
    if(uni(u,v)){
        printf("edge %d (%d %d) cost %d\n",ne++,a,b,min);
        mincost = mincost + min;
    }

    cost[a][b] = cost[b][a] = 999;

}
printf("\nmin cost %d",mincost);


return 0;
}

int find(int i)
{
    while(parent[i]){
        i = parent[i];
    }
    return i;
}


int uni(int i,int j)
{
    if(i!=j){
        parent[j] = i;
        return 1;
    }
    else return 0;
}
