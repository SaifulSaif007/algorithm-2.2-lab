#include<bits/stdc++.h>
using namespace std;
int size1;
int S[100][100];
int MatrixChainOrder(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;
    for (i = 1; i < n; i++){
        m[i][i] = 0;
    }
    for (L=2; L<n; L++)
    {
        for (i=1; i<=n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]){
                    m[i][j] = q;
                    S[i][j]=k;
                }
            }
        }
    }
    for(i=1;i<n;i++){
        for(j=2;j<n;j++){
            printf("\t%d",m[i][j]);
        }
        printf("\n");
    }
     printf("\n\n\n");
    for(i=1;i<n-1;i++){
        for(j=2;j<n;j++){
            printf("\t%d",S[i][j]);
        }
        printf("\n");
    }
    return m[1][n-1];
}

int main()
{
    int size1,i,n,m;
    int arr[100];
    printf("number of element: ");
    scanf("%d",&size1);
    printf("\nelement of array : \n");
    for(i=0;i<size1;i++){
        scanf("%d",&arr[i]);
    }
    m=MatrixChainOrder(arr, size1);
    printf("\n\n\n");
    printf(": %d",m);
    return 0;
}
/*
7
30 35 15 5 10 20 25
*/

