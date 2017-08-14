#include <stdio.h>
#include <stdlib.h>
int G[20][20] , distance[20] , inSet[20] , q[20] , parent[20] ;
void print( int V )
{
    int i ;
    for ( i = 0 ; i < V ; i++ )
        printf("i = %d parent = %d distance from source = %d \n", i + 1 , parent[i] , distance[i] ) ;
}
int Q( int V )
{
    int sum = 0 , i ;
    for( i = 0 ; i < V ; i++ )
        sum += q[i] ;
    return sum;
}
int extractMin( int V )
{
    int i , idx , min = 99999 ;
    for ( i = 0 ; i < V ; i++ )
    {
        if ( distance[i] <= min && inSet[i] == 0 )
            min = distance[i] , idx = i ;
    }
    q[idx] = 0 ;
    return idx ;
}
void dijkstra ( int S , int V )
{
    int u , i , check_empty = Q(V);

    while( check_empty >0 )
    {
        u = extractMin(V) ;

        inSet[u] = 1 ;
        q[u] = 0 ;
        for( i = 0 ; i < V ; i++ )
        {
            if( G[u][i] > 0 )
            {
                if( distance[u] + G[u][i] < distance[i] )
                    distance[i] = distance[u] + G[u][i] , parent[i] = u + 1 ;
            }
        }
        check_empty = Q(V);
    }

    print(V);
}
int main()
{
    int V , i , j , S;
    printf ( "Enter no. of vertices: " ) ;
    scanf ( "%d" , &V ) ;

    printf ( "Enter graph in matrix form:\n" ) ;
    for ( i = 0 ; i < V ; i++ )
    {
        for( j = 0 ; j < V ; j++ )
            scanf( "%d" , &G[i][j] );
    }
    for ( i = 0 ; i < V ; i++ )
        distance[i] = 1000 , inSet[i] = 0 , q[i] = 1 , parent[i] = -1 ;

    printf ( "Enter the source vertex: " ) ;
    scanf ( "%d" , &S ) ;
    distance[ S - 1 ] = 0 ;
    dijkstra ( S , V ) ;
    return 0;
}
