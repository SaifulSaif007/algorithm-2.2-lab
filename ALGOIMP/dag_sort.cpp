#include<cstdio>
#include<climits>
#include<stack>
#include<queue>

using namespace std;
int a[10][10],vis[10],d[100],prevx[100],cst[10][10];
void single_source(int,int);
void relax(int,int);
void DAG(int,int);

int main(void){

int i,j,v,s;
printf("Enter Number of vertices: \n");
scanf("%d",&v);
printf("Enter Adjacent Matrix: \n");
for(i=1;i<=v;i++){
    for(j=1;j<=v;j++){
     scanf("%d",&a[i][j]);
    }
}
for(i=1;i<=v;i++){
    for(j=1;j<=v;j++){
       if(a[i][j]==1){
        printf("Cost for %d to %d: ",i,j);
        scanf("%d",&cst[i][j]);
        printf("\n");
       }

    }
}


printf("Enter Source: \n");
scanf("%d",&s);
DAG(v,s);

return 0;
}
void single_source(int v,int s){
   for(int i=1;i<=v;i++){
    d[i]=INT_MAX;
    prevx[i]=NULL;
   }
   d[s]=0;
}
void relax(int v,int s){
        for(int i=s+1;i<=v;i++){
                if(a[s][i]==1){
                        if(d[i]>d[s]+cst[s][i]){
                            d[i]=d[s]+cst[s][i];
                            prevx[i]=s;
                        }
                        relax(v,i);

                }
            }

    }



//}
void DAG(int v,int s){
    int i,t;
    single_source(v,s);
    relax(v,s);
    printf("cost for node 1: %d\n",d[s]);
    for(i=s+1;i<=v;i++){
    printf("cost for node %d: %d & from Node: %d\n",i,d[i],prevx[i]);
    }

    printf("\n");
    printf("enter Target: \n");
    scanf("%d",&t);

  i=t;
   printf("Path: ");
   printf("%d",t);
    while(i>s){

    printf("<--%d",prevx[i]);


     i=prevx[i];



}
  //printf("%d",s);
}


