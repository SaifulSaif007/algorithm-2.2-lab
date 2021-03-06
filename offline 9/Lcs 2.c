#include<stdio.h>
#include<string.h>
#define maxn 100100
int max(int a,int b)
{
        return a>b?a:b;
}
int LongestCommonSubsequence(char S[],char T[])
{
        int Slength = strlen(S);
        int Tlength = strlen(T);
        int iter,jter;
        for(iter=Slength;iter>=1;iter--)
        {
                S[iter] = S[iter-1];
        }
        for(iter=Tlength;iter>=1;iter--)
        {
                T[iter] = T[iter-1];
        }
        int common[Slength+1][Tlength+1];

        for(iter=0;iter<=Tlength;iter++)
        {
                common[0][iter]=0;
        }

        for(iter=0;iter<=Slength;iter++)
        {
                common[iter][0]=0;
        }
        for(iter=1;iter<=Slength;iter++)
        {
                for(jter=1;jter<=Tlength;jter++)
                {
                        if(S[iter] == T[jter] )
                        {
                                common[iter][jter] = common[iter-1][jter-1] + 1;
                        }
                        else
                        {
                                common[iter][jter] = max(common[iter][jter-1],common[iter-1][jter]);
                        }

                }
        }
        return common[Slength][Tlength];

}
int main()
{
        char S[maxn],T[maxn];
        scanf("%s%s",S,T);
        printf("%d",LongestCommonSubsequence(S,T));
        return 0;

}
