#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,k;
int a[N];
int y[N],m[N],x[N][N];
struct E{
    int nxt,to,dis;
}edge[M];
struct node{
    int pos,dis;
    bool operator < (const node &x) const{
        return x.dis<dis;
    }
};
priority_queue<node> q;
int head[N],num_edge;
void add(int from,int to,int dis){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    edge[num_edge].dis=dis;
    head[from]=num_edge;
}
int dis[N];
bool vis[N];
void djikstra(int s){
    memset(dis,INF,sizeof(dis));
    dis[s]=0;
    q.push((node){s,0});
    while(!q.empty()){
        int t=q.top().pos;
        q.pop();
        if(vis[t]) continue;
        vis[t]=1;
        for(int i=head[t];i;i=edge[i].nxt){
            int j=edge[i].to;
            if(dis[j]>dis[t]+edge[i].dis){
                dis[j]=dis[t]+edge[i].dis;
                if(!vis[j]) q.push((node){j,dis[j]});
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf("%d %d",&y[i],&m[i]);
        for(int j=1;j<=m[i];j++){
            scanf("%d",&x[i][j]);
        }
    }
    return 0;
}