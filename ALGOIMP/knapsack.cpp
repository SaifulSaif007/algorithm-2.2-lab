#include<stdio.h>
#include<iostream>
#include <string.h>
#define MAXA 100
#define MAXW 1000
using namespace std;

int n;
int cnt = 0;
int c[MAXA+1];
int dp[MAXA+1][MAXW+1];
int w[MAXA+1];
int capacity;

int max(int x,int y){

cout<<" maximum between profit 1 = "<<x<<" and profit 2 = "<<y<<endl;

    if(x>y)
        return x;
    else
        return y;
}
int f(int i,int we)
{
    cout<<"i = "<<i<<" we = "<<we<<endl;
    int pro1=0,pro2=0;

	if(i==n+1) {
        cout<<" return 0"<<endl;
        return 0;
	}
	if(dp[i][we]!=-1){
            cout<<"dp[i][we] "<<dp[i][we]<<endl<<endl;
        return dp[i][we];
    }

	int curr_cap = we+w[i];
	cout<<"current capacity "<<curr_cap<<endl;
	if(curr_cap<=capacity){
        cout<<"function within for i "<<i+1<<" weight "<<curr_cap<<" and "<<" cost "<<c[i]<<endl;
		pro1=c[i]+f(i+1,curr_cap);
        printf("Profit 1: %d\n",pro1);
	}
    cout<<"function outside for i "<<i+1<<" weight "<< we<<endl;
	pro2=f(i+1,we);
	printf("Profit 2: %d\n",pro2);
	dp[i][we]=max(pro1,pro2);

	printf("    return value %d\n\n", dp[i][we]);
	return dp[i][we];
}
int main()
{

	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&n,&capacity);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&w[i],&c[i]);
	}
	printf("Final Result is : %d\n\n\n",f(1,0));


}
