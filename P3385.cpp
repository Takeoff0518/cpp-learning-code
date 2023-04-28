#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (2005)
#define M (6005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int t,n,m;
struct E{
    int nxt,to,v;
}edge[M];
int head[N],num_edge;
void add(int from,int to,int dis){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    edge[num_edge].v=dis;
    head[from]=num_edge;
}
bool vis[N];
int dis[N],cnt[N];
queue<int> q;
bool SPFA(int s){
    queue<int>().swap(q);
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    dis[s]=0,vis[s]=1,cnt[s]++;
    q.push(s);
    while(!q.empty()){
        int t=q.front(); q.pop();
        vis[t]=0;
        for(int i=head[t];i;i=edge[i].nxt){
            int j=edge[i].to;
            if(dis[j]>dis[t]+edge[i].v){
                dis[j]=dis[t]+edge[i].v;
                if(vis[j]==0){
                    vis[j]=1;
                    q.push(j); cnt[j]++;
                }
                if(cnt[j]>n) return 1;
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        num_edge=0;
        memset(head,0,sizeof(head));
        for(int i=1,u,v,w;i<=m;i++){
            scanf("%d %d %d",&u,&v,&w);
            if(w>=0){
                add(u,v,w); add(v,u,w);
            }else add(u,v,w);
        }
        if(SPFA(1)) puts("YES");
        else puts("NO");
    }
    return 0;
}