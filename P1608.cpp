#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define INF 0x3f3f3f3f
#define ll long long
#define N 2005
#define M (N*(N-1))
using namespace std;
int n,m;
int dis[N],cnt[N];
bool vis[N];
// int head[N],num_edge;
int g[N][N];
// struct Edge{
//     int nxt,to,dis;
// }edge[M];
struct node{
    int idx,dis;
    bool operator < (const node &x) const{
        return x.dis<dis;
    }
};
priority_queue<node> q;
// void add(int from,int to,int dis){
//     num_edge++;
//     edge[num_edge].nxt=head[from];
//     edge[num_edge].to=to;
//     edge[num_edge].dis=dis;
//     head[from]=num_edge;
// }
void djikstra(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    cnt[1]=1;
    q.push((node){s,0});
    while(!q.empty()){
        node tmp=q.top();
        q.pop();
        int min_i=tmp.idx;
        if(vis[min_i]){
            continue;
        }
        vis[min_i]=1;
        for(int i=1;i<=n;i++){
            if(dis[i]>dis[min_i]+g[min_i][i]){
                dis[i]=dis[min_i]+g[min_i][i];
                cnt[i]=cnt[min_i];
                if(!vis[i]){
                    q.push((node){i,dis[i]});
                }
            }else if(dis[i]==dis[min_i]+g[min_i][i]){
                cnt[i]+=cnt[min_i];

            }
        }

        // for(int i=head[min_i];i;i=edge[i].nxt){
        //     int p=edge[i].to;
        //     if(dis[p]>dis[min_i]+edge[i].dis){
        //         dis[p]=dis[min_i]+edge[i].dis;
        //         cnt[p]=cnt[min_i];
        //         if(!vis[p]){
        //             q.push((node){p,dis[p]});
        //         }
        //     }else if(dis[p]==dis[min_i]+edge[i].dis){
        //         cnt[p]+=cnt[min_i];
        //     }
        // }
    }
}
int main(){
    memset(g,0x3f,sizeof(g));
    scanf("%d %d",&n,&m);
    for(int i=1,u,v,w;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u][v]=min(g[u][v],w);
        // add(u,v,w);
    }
    djikstra(1);
    if(dis[n]!=dis[0])
        printf("%d %d\n",dis[n],cnt[n]);
    else
        puts("No answer");
    return 0;
}