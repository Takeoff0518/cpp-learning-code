#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#define N 100005
using namespace std;
struct Edge{
    int nxt,to,dis;
}edge[N*2];
struct node{
    int dis,pos;
    bool operator < (const node &x) const{
        return x.dis<dis;
    }
};
priority_queue<node>q;
int num_edge,head[N],dis[N];
bool vis[N];
int n,m,s;
void add(int from,int to,int dis){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    edge[num_edge].dis=dis;
    head[from]=num_edge;
}
int main(){
    scanf("%d %d %d",&n,&m,&s);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        add(u,v,w);
    }
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    q.push((node){0,s});
    while(!q.empty()){
        node tmp=q.top();
        q.pop();
        int min_i=tmp.pos;
        if(vis[min_i]==1)
            continue;
        vis[min_i]=1;
        for(int i=head[min_i];i;i=edge[i].nxt){
            int p=edge[i].to;
            if(dis[p]>dis[min_i]+edge[i].dis){
                dis[p]=dis[min_i]+edge[i].dis;
                if(vis[p]==0){
                    q.push((node){dis[p],p});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",dis[i]);
    }
    return 0;
}