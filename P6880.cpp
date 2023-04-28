#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define INF 0x3f3f3f3f
#define ll long long
#define N 205
#define M 100005
using namespace std;
int n,m;
int g[N][N],dis[N],dj[N][N];
bool vis[N];
int ans=INF;
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
struct node{
    int pos,dis;
    bool operator < (const node &x) const{
        return x.dis<dis;
    }
};
void djikstra(int s){
    priority_queue<node> q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
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
                if(!vis[p]){
                    q.push((node){p,dis[p]});
                }
            }
        }
    }
}
void print_dis(){
    for(int i=1;i<=2*n;i++){
        printf("%d ",dis[i]);
    }
    puts("");
}
int main(){
    scanf("%d %d",&n,&m);
    memset(g,0x3f,sizeof(g));
    for(int i=1,u,v,w,c;i<=m;i++){
        scanf("%d %d %d %d",&u,&v,&w,&c);
        g[u][v]=min(g[u][v],w);
        dj[u][v]=dj[v][u]=c;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(g[i][j]!=INF){
                add(i,j,g[i][j]);
                add(i+n,j+n,g[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(g[i][j]!=INF && g[j][i]==INF){//i->j
                add(j,i+n,g[i][j]+dj[i][j]);
                printf("add %d->%d,val=%d+%d=%d\n",j,i+n,g[i][j],dj[i][j],g[i][j]+dj[i][j]);
            }
        }
    }
    int dis1,dis2,dis3,dis4,dis5;
    djikstra(1);
    //print_dis();
    dis1=dis[n],dis2=dis[2*n];
    if(dis[n]!=INF){
        djikstra(n);
        //print_dis();
        dis3=dis[1],dis4=dis[n+1];
        printf("%d %d\n",dis1+dis3,dis1+dis4);
        ans=min(ans,min(dis1+dis3,dis1+dis4));
    }
    if(dis[2*n]!=INF){
        djikstra(2*n);
        //print_dis();
        dis5=dis[n+1];
        printf("%d %d \n",dis2,dis5);
        ans=min(ans,dis2+dis5);
    }
    if(ans>=INF){
        puts("-1");
    }else{
        printf("%d\n",ans);
    }
    return 0;
}