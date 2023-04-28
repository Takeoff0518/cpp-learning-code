#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define INF 0x3f3f3f3f
#define ll long long
#define N 100005
#define M 500005
using namespace std;
struct E{
    int nxt,to,v;
}edge[M*6+N*2];
queue<int> q;
int head[N*3],num_edge;
void add(int from,int to,int dis){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    edge[num_edge].v=dis;
    head[from]=num_edge;
}
int n,m;
int val[N*3];
int dis[N*3];
bool vis[N*3];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
        add(i,i+n,-val[i]);
        add(i+n,i+2*n,val[i]);
    }
    for(int i=1;i<=m;i++){
        int u,v,opt;
        scanf("%d %d %d",&u,&v,&opt);
        //int earn=val[v]-val[u];
        add(u,v,0);
        add(u+n,v+n,0);
        add(u+2*n,v+2*n,0);
        if(opt==2){
            add(v,u,0);
            add(v+n,u+n,0);
            add(v+2*n,u+2*n,0);
        }
    }
    //SPFA
    memset(dis,-INF,sizeof(dis));
    dis[1]=0,vis[1]=1;
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=edge[i].nxt){
            int j=edge[i].to;
            if(dis[j]<dis[u]+edge[i].v){
                dis[j]=dis[u]+edge[i].v;
                if(!vis[j]){
                    vis[j]=1;
                    q.push(j);
                }
            }
        }
    }
    // for(int i=1;i<=3*n;i++){
    //     printf("%d ",dis[i]);
    // }
    // puts("");
    printf("%d\n",max(dis[n],dis[n*3])); 
    return 0;
}