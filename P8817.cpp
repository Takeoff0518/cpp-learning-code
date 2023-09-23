#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,k;
int s[N];
bool g[N][N],vis[N];
int dis[N][N];
set<PII> st[N];
void bfs(int s){
    queue<int> q;
    memset(vis,0,sizeof(vis));
    memset(dis[s],INF,sizeof(dis[s]));
    dis[s][s]=0; q.push(s);
    while(!q.empty()){
        int t=q.front(); q.pop();
        if(vis[t]) continue; vis[t]=1;
        for(int i=1;i<=n;i++){
            if(dis[s][i]!=INF && dis[s][i]>dis[s][t]+1){
                dis[s][i]=dis[s][t]+1;
                q.push(s);
            }
        }
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=2;i<=n;i++){
        scanf("%d",&s[i]);
    }
    for(int i=1,u,v;i<=m;i++){
        scanf("%d %d",&u,&v);
        g[u][v]=g[v][u]=1;
    }
    for(int i=1;i<=n;i++){
        bfs(i);
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            if(i==j) continue;
            if(dis[i][j]<=k+1 && dis[1][j]<=k+1)
                st[i].insert({s[j],j});
            if(st[i].size()>3)
                st[i].erase(st[i].begin());
        }
    }
    return 0;
}