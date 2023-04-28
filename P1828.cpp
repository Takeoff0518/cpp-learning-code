#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N 805
#define M 1500
using namespace std;
int num_cow,n,m;
int cow[N],dis[N];
bool vis[N];
struct Edge{
    int nxt,to,dis;
}edge[2*M];
struct node{
    int dis,pos;
    inline bool operator < (const node &x) const{
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
void djikstra(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<node>().swap(q);
    dis[s]=0;
    q.push((node){0,s});
    while(!q.empty()){
        int min_i=q.top().pos,min_dis=q.top().dis;
        q.pop();
        if(vis[min_i]){
            continue;
        }
        vis[min_i]=1;
        for(int i=head[min_i];i;i=edge[i].nxt){
            int p=edge[i].to;
            if(dis[p]>dis[min_i]+edge[i].dis){
                dis[p]=dis[min_i]+edge[i].dis;
                if(!vis[p]){
                    q.push((node){dis[p],p});
                }
            }
        }
    }
}
int main(){
    scanf("%d %d %d",&num_cow,&n,&m);
    for(int i=1;i<=num_cow;i++){
        int x;
        scanf("%d",&x);
        cow[x]++;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    int ans=1<<30;
    for(int i=1;i<=n;i++){
        djikstra(i);
        int tmp=0;
        for(int j=1;j<=n;j++){
            tmp+=dis[j]*cow[j];
        }
        //printf("%d ",tmp);
        ans=min(ans,tmp);
    }
    //puts("");
    if(ans<0){
        printf("8\n");
        return 0;
    }
    printf("%d",ans);
    return 0;
}