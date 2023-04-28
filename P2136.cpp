#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (1005)
#define M (20005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
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
queue<int> q;
int dis[N],cnt[N];
bool vis[N];
void SPFA(int s){
    queue<int>().swap(q);
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    dis[s]=0,vis[s]=1;
    q.push(s); cnt[s]=1;
    while(!q.empty()){
        int t=q.front(); q.pop();
        // printf("top=%d\n",t);
        vis[t]=0;
        for(int i=head[t];i;i=edge[i].nxt){
            int j=edge[i].to;
            if(dis[j]>dis[t]+edge[i].v){
                dis[j]=dis[t]+edge[i].v;
                if(!vis[j]){
                    vis[j]=1;
                    q.push(j);
                    cnt[j]++;
                }
                if(cnt[j]>n){
                    puts("Forever love");
                    exit(0);
                }
            }
            
        }
    }
    // return false;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1,u,v,w;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,-w);
    }
    int ans1,ans2;
    SPFA(1); ans1=dis[n];
    // for(int i=1;i<=n;i++){
    //     printf("%d ",dis[i]);
    // }
    // puts("");
    // for(int i=1;i<=n;i++){
    //     printf("%d ",dis[i]);
    // }
    // puts("");
    SPFA(n); ans2=dis[1];
    // printf("%d %d\n",ans1,ans2);
    printf("%d\n",min(ans1,ans2));
    return 0;
}