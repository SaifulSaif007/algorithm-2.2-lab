#include <bits/stdc++.h>
#define MAX 100
#define INIFINITY 999

using namespace std;

int tsp_dp (int c[][MAX], int tour[], int start, int n)
{
    int i, j, k;
    int temp[MAX];
    int mintour[MAX];
    int mincost;
    int ccost;
    /* End of recursion condition. */
    /* Compute the tour starting from the current city. */
    mincost = INFINITY;
    for (i=start+1;i<n;i++){
        for (j=0; j<n; j++){
            temp[j] = tour[j];
        }
        /* Adjust positions. */
        temp[start+1] = tour[i];
        temp[i] = tour[start+1];
        /* Found a better cycle? (Recurrence derivable.) */
        if(c[tour[start]][tour[i]]+(ccost = tsp_dp (c, temp, start+1, n)) < mincost){
            mincost = c[tour[start]][tour[i]] + ccost;
            for(k=0;k<n;k++){
                mintour[k]=temp[k];
            }
        }
    }
     if (start==n-2){
        return c[tour[n-2]][tour[n-1]] + c[tour[n-1]][0];
    }
    /* Set the minimum-tour array. */
    for (i=0; i<n; i++){
        tour[i] = mintour[i];
    }

    return mincost;
}

int main(){

    int n;
    int c[MAX][MAX];
    int tour[MAX];
    int cost;

    cin>>n;

      for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>c[i][j];
        }
    }
    for(int i=0; i<n; i++){
        tour[i] = i;
    }
    cost = tsp_dp(c,tour,0,n);
    cout<<cost;
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<tour[i]+1<<" ";
    }
    cout<<"1"<<endl;
}
