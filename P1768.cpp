#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (7005)
#define M (20005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
#define eps (1e-3)
using namespace std;
int n,m;
struct E{
    int nxt,to,v,p;
    double dis;
    E(){
        dis=0.0;
    }
}edge[M];
int head[N],num_edge;
void add(int from,int to,int v,int p){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    edge[num_edge].v=v;
    edge[num_edge].p=p;
    head[from]=num_edge;
}
queue<int> q;
double dis[N];int cnt[N];
bool vis[N];
bool SPFA(){
    queue<int>().swap(q);
    memset(vis,0,sizeof(vis));
    memset(dis,127,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    dis[0]=0.0,vis[0]=1,cnt[0]++;
    q.push(0);
    while(!q.empty()){
        int t=q.front(); q.pop();
        vis[t]=0;
        for(int i=head[t];i;i=edge[i].nxt){
            int j=edge[i].to;
            if(dis[j]>dis[t]+edge[i].dis){
                dis[j]=dis[t]+edge[i].dis;
                if(vis[j]==0){
                    vis[j]=1;
                    q.push(j); cnt[j]++;
                }
                if(cnt[j]>10) return true;
            }
        }
    }
    return false;
}
int main(){
    memset(head,0,sizeof(head));
    scanf("%d %d",&n,&m);
    for(int i=1,from,to,v,p;i<=m;i++){
        scanf("%d %d %d %d",&from,&to,&v,&p);
        add(from,to,v,p);
    }
    for(int i=1;i<=n;i++) add(0,i,0,0);
    double l=0.0,r=200.0,mid;
    while(l+eps<r){
        mid=(l+r)/2;
        for(int i=1;i<=num_edge;i++){
            edge[i].dis=(double)edge[i].p*mid-edge[i].v;
        }
        if(SPFA()) l=mid;
        else r=mid;
    }
    if(l==0) printf("-1\n");
    else printf("%.1lf\n",l);
    return 0;
}