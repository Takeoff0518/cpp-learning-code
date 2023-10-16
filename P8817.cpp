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
int dis[N][N];
struct E{
    int nxt,to;
}edge[M];
int head[N],num_edge;
void add(int from,int to){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    head[from]=num_edge;
}
int rank[N][5];
bool vis[N];
void bfs(int *d,int s){
    queue<int> q;
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[s]=0;
    q.push(s);
    while(!q.empty()){
        int t=q.front(); q.pop();
        if(vis[t]) continue;
        vis[t]=1;
        for(int i=head[t];i;i=edge[i].nxt){
            int j=edge[i].to;
            if(d[j]>d[t]+1){
                d[j]=d[t]+1;
                if(!vis[j]) q.push(j);
            }
        }
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<n;i++) scanf("%d",&s[i]);
    for(int i=1,u,v;i<=m;i++){
        scanf("%d %d",&u,&v);
    }
    return 0;
}