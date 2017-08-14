#include<conio.h>
#include<stdio.h>
#include<math.h>

#define TRUE 1
#define FALSE 0
#define MAXBOARDSIZE 11

int board[MAXBOARDSIZE];
int n;

void PrintBoard()
{
    int i, k;
    static int solno=1;

    printf("\nSolution %d:\n", solno++);
    for (i = 0; i < n; i++)
    {
        for (k = 0; k < board[i]; k++)
            printf("  ");
        printf("%2d\n", board[i]+1);
    }
}

int IsPlaceSafe(int row, int col)
{
    int i;

    for(i=0; i<row; i++)
    {
        if( (board[i] == col) || (abs(board[i]-col) == abs(i-row)) )
            return 0;
    }
    return 1;
}

void NQueens(int row)
{
    int col;

    for(col=0; col<n; col++)
    {
        if(IsPlaceSafe(row, col))
        {
            board[row] = col;
            if(row == n-1)
                PrintBoard();
            else
                NQueens(row+1);
        }
    }
}

int main()
{
    int i;

    printf("Enter board size: ");
    scanf("%d", &n);
    if(n>MAXBOARDSIZE) exit(1);

    NQueens(0);
    getch();
    return 0;
}
