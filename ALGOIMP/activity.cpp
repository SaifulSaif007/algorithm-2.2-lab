#include<bits/stdc++.h>
using namespace std;

void activitiy_Selection(int s[],int f[],int n);
int main(void)
{
    int n;


int s[]={1,3,0,5,3,5,6,8,8,2,12};


	int f[]={4,5,6,7,9,9,10,11,12,14,16};

	n= sizeof(s)/sizeof(s[0]);
	activitiy_Selection(s, f, n);
    return 0;
}
void activitiy_Selection(int s[],int f[],int n)
{
	int i, j;
	i = 1;
    cout<<"Output :  \n"<<i<<"\t";
	for (j = 1; j < n; j++)
		if (s[j] >= f[i])
		{
			cout<<"\n"<<(j+1);
			i = j;
		}
}
