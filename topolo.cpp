#include<bits/stdc++.h>
using namespace std;
const int maxn=1100;
int c[maxn];
bool G[maxn][maxn];
int topo[maxn],t,n,m,x,y;
bool dfs(int u)
{
    c[u]=-1;//访问标志-1正在访问，1已经访问，0尚未访问
    for(int v=0; v<n; v++)
        if(G[u][v])
        {
            if(c[v]<0) return false;//存在环路
            else if(!c[v]&&!dfs(v)) return false;
        }
    c[u]=1;
    topo[--t]=u;
    return true;
}
bool toposort()
{
    t=n;
    memset(c,0,sizeof(c));
    for(int u=0; u<n; u++)
        if(!c[u]&&!dfs(u))
            return false;
    return true;
}
int main()
{
    while(cin>>n>>m&&n)
    {
        memset(G,0,sizeof(G));
        while(m--)
        {
            cin>>x>>y;
            G[x-1][y-1]=1;
        }
        if(toposort())
            for(int i=0; i<n; i++)
                cout<<topo[i]+1<<(i==n-1?"\n":" ");
        else cout<<"This is not a DAG!"<<endl;
    }
    return 0;
}

