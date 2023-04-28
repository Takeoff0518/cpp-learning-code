#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define INF 0x3f3f3f3f
#define ll long long
#define N 100005*42
#define M 500005*42
using namespace std;
struct E{
    int nxt,to,v;
}edge[M];
int head[N],num_edge;
void add(int from,int to,int dis){
    //printf("add:%d->%d,val=%d\n",from,to,dis);
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    edge[num_edge].v=dis;
    head[from]=num_edge;
}
struct node{
    int pos,dis;
    inline bool operator < (const node &x) const{
        return x.dis<dis;
    }
};
int dis[N];
bool vis[N];
int n,m,n;
priority_queue<node> q;
void djikstra(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    q.push((node){s,0});
    while(!q.empty()){
        node tmp=q.top();
        q.pop();
        int min_i=tmp.pos;
        if(vis[min_i]){
            continue;
        }
        vis[min_i]=true;
        for(int i=head[min_i];i;i=edge[i].nxt){
            int p=edge[i].to;
            if(dis[p]>dis[min_i]+edge[i].v){
                dis[p]=dis[min_i]+edge[i].v;
                //if(!vis[p]){
                    q.push((node){p,dis[p]});
                //}
            }
        }
    }
}
// int get_val(int x,int y){
//     for(int i=head[x];i;i=edge[i].nxt){
//         if(edge[i].to==y){
//             return edge[i].dis;
//         }
//     }
//     return -1;
// }
int ans=INF;
void debug(bool g[]){
    for(int i=1;i<=n;i++){
        printf("%d ",g[i]);
    }
    puts("");
}
int main(){
    // freopen("P2939_2.in","r",stdin);
    // freopen("P2932_2.txt","w",stdout);
    scanf("%d %d %d",&n,&m,&n);
    for(int i=1,u,v,w;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
        for(int j=1;j<=n;j++){
            add(u+j*n,v+j*n,w);
            add(v+j*n,u+j*n,w);

            add(u+(j-1)*n,v+j*n,0);
            add(v+(j-1)*n,u+j*n,0);
        }
    }
    for(int i=1;i<=n;i++){
        add(n+(i-1)*n,n+i*n,0);
    }
    djikstra(1);
    for(int i=0;i<=n;i++){
        ans=min(ans,dis[n+i*n]);
    }
    printf("%d\n",ans);
    return 0;
}