#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define INF 0x3f3f3f3f
#define ll long long
#define N 300005
#define M 500005
using namespace std;
struct E{
    int nxt,to,v;
}edge[6*M+N];
struct node{
    int dis,pos;
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
    edge[num_edge].v=dis;
    head[from]=num_edge;
}
int n,m;
int val[N];
int dis[N];
bool vis[N];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
    }
    for(int i=1;i<=m;i++){
        int u,v,opt;
        scanf("%d %d %d",&u,&v,&opt);
        //int earn=val[v]-val[u];
        if(opt==1){
            for(int j=0;j<3;j++){
                add(u+j*n,v+j*n,0);
            }
            add(u,v+n,val[u]);
            add(u+n,v+2*n,-val[u]);
        }else{
            for(int j=0;j<3;j++){
                add(u+j*n,v+j*n,0);
                add(v+j*n,u+j*n,0);
            }
            add(u,v+n,val[u]);
            add(u+n,v+2*n,-val[u]);

            add(v,u+n,val[v]);
            add(v+n,u+2*n,-val[v]);
        }
    }
    memset(dis,INF,sizeof(dis));
    dis[1]=0;
    q.push((node){0,1});
    while(!q.empty()){
        node tmp=q.top();
        q.pop();
        int min_i=tmp.pos,min_dis=tmp.dis;
        if(vis[min_i]){
            continue;
        }
        vis[min_i]=1;
        for(int i=head[min_i];i;i=edge[i].nxt){
            int j=edge[i].to;
            if(dis[j]>dis[min_i]+edge[i].v){
                dis[j]=dis[min_i]+edge[i].v;
            }
            if(!vis[j]){
                q.push((node){dis[j],j});
            }
        }
    }
    // for(int i=1;i<=3*n;i++){
    //     printf("%d ",dis[i]);
    // }
    // puts("");
    printf("%d\n",max(0,-dis[n*3])); 
    return 0;
}