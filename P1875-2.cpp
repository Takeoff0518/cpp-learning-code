#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int dis[1001];
int g[1001][1001];
bool vis[1001];
int cnt[1001];
void dijkstra()
{
    for(int i=1;i<=n;i++)
    {
        int u,t=2100000000;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&dis[j]<t)
            {
                u=j;
                t=dis[j];
            }
        }
        if(t==2100000000)break;
        vis[u]=true;
        for(int j=1;j<=n;j++)
        {
            if(!g[u][j])continue;
            if(!vis[j])continue;
            if(dis[g[u][j]]>t+dis[j])
            {
                dis[g[u][j]]=t+dis[j];
                cnt[g[u][j]]=cnt[u]*cnt[j];
            }
            else if(dis[g[u][j]]==t+dis[j])
            cnt[g[u][j]]+=cnt[u]*cnt[j];
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%d",&dis[i]),cnt[i]=1;
    int u,v,t;
    while(scanf("%d%d%d",&u,&v,&t)!=EOF)
    {
        g[u+1][v+1]=t+1;
        g[v+1][u+1]=t+1;
    }
    dijkstra();
    printf("%d %d",dis[1],cnt[1]);
    return 0;
}
