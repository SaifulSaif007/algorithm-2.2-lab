#include <bits/stdc++.h>
using namespace std;
#define inf 999999999
int nod,edge;
int matCost[100][100];
int matParent[100][100];
int main()
{
    scanf("%d %d",&nod,&edge);
    for(int i=1;i<=nod;i++){
        for(int j=1;j<edge;j++){
            if(i==j){
                matCost[i][j]=0;
                matParent[i][j]=0;
            }
            else{
                matCost[i][j]=inf;
                matParent[i][j]=i;
            }
        }
    }

    for(int i=0;i<edge;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        matCost[a][b]=c;
    }

    for(int k=1;k<=nod;k++){
        for(int i=1;i<=nod;i++){
            for(int j=1;j<=nod;j++){
                if(matCost[i][k]+matCost[k][j]<matCost[i][j]){
                    matCost[i][j]=matCost[i][k]+matCost[k][j];
                    matParent[i][j]=matParent[k][j];
                }
            }
        }
    }

    printf("\nCost : \n\n");

    for(int i=1;i<=nod;i++){
        for(int j=1;j<=nod;j++){
            printf("%d  ",matCost[i][j]);
        }
        printf("\n");
    }

    printf("\nParent : \n\n");

    for(int i=1;i<=nod;i++){
        for(int j=1;j<=nod;j++){
            printf("%d  ",matParent[i][j]);
        }
        printf("\n");
    }
}

/*

5 9
1 2 3
1 3 8
1 5 -4
2 5 7
2 4 1
3 2 4
4 1 2
4 3 -5
5 4 6

*/
