#include<stdio.h>
#include<string.h>

int i,j,m,n,a,c[20][20]={0},count=0,e,f;
char x[15],y[15],b[20][20]={0};

void main()
{
    printf("Enter 1st sequence : ");
    gets(x);
    printf("Enter 2nd sequence : ");
    gets(y);
    printf("\nlongest common subsequence is : ");
    lcs_length();

    printf("\n\ntotal subsequence length : %d\n",count);

        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                printf("\t%d",c[i][j]);
            }
            printf("\n");
        }


    printf("\n");
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                printf("\t%c",b[i][j]);
                }
                printf("\n");
        }
}


void print_lcs(int i,int j)
{
        if(i==0 || j==0)
                return;
        if(b[i][j]=='c')
    {
            print_lcs(i-1,j-1);
            printf(" %c",x[i-1]);
            count++;
        }
        else if(b[i][j]=='u')
                print_lcs(i-1,j);
            else
                print_lcs(i,j-1);
}
void lcs_length(void)
{
        m=strlen(x);
        n=strlen(y);

         for(i=1;i<=m;i++){
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

        print_lcs(m,n);
    }



}
