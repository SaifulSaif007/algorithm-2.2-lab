#include<stdio.h>
#include<conio.h>
#include<string.h>

int i,j,m,n,a,c[20][20];
char x[20],y[20],b[20][20];

void print_lcs(int i,int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    if(b[i][j]=='c')
    {
        print_lcs(i-1,j-1);
        printf(" %c",x[i-1]);
    }
    else if(b[i][j]=='u')
    {
        print_lcs(i-1,j);
    }
    else
    {
        print_lcs(i,j-1);
    }
}

void lcs_length(void)
{
    m=strlen(x);
    n=strlen(y);
    for(i=1;i<=m;i++)
    {
    c[i][0]=0;
    }
    for(i=0;i<=n;i++)
    {
    c[0][i]=0;
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='c';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
    }
    print_lcs(m,n);
 }

void main()
{
    printf("Enter the 1st Sequence : ");
    gets(x);
    printf("Enter the 2nd Sequence : ");
    gets(y);
    printf("\nLongest Common Subsequence is: ");
    lcs_length();
    printf("\n%d",c[m][n]);
}
/*abcbdab
bdcaba
*/
