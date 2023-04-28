#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue> 
#define INF 0x3f3f3f3f
#define ll long long
#define N 100005
#define M 2000005
using namespace std;
int n,m;
ll sum;
int num_edge=1;
int h[N];
int fa[N];
struct node{
    int from,to,dis;
}s[M];
struct E{
    int nxt,to,v;
}edge[M];
int head[N],num_edge,num_edge2;
void add_kru(int from,int to,int dis){
    num_edge2++;
    s[num_edge2].from=from;
    s[num_edge2].to=to;
    s[num_edge2].dis=dis;
}
void add(int from,int to,int dis){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    edge[num_edge].v=dis;
    head[from]=num_edge;
}
int findfa(int x){
    if(x!=fa[x]){
        fa[x]=findfa(fa[x]);
    }
    return fa[x];
}
inline void unionn(int x,int y){
    x=findfa(x),y=findfa(y);
    if(x!=y){
        fa[x]=y;
    }
}
inline bool check(int x,int y){
    return findfa(x)==findfa(y);
}
int vis[N];
void bfs(){
    queue<int> q;
    vis[1]=1;
    q.push(1);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(int i=head[front];i;i=edge[i].nxt){
            add_kru(front,edge[i].to,edge[i].v);
            if(!vis[edge[i].to]){
                vis[edge[i].to]=1;
                num_edge++;
                q.push(edge[i].to);
            }
        }
    }
}
inline bool cmp(node x,node y){
    if(h[x.to]!=h[y.to]){
        return h[x.to]>h[y.to];
    }
    return x.dis<y.dis;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
        fa[i]=i;
    }
    for(int i=1,u,v,w;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        if(h[u]>=h[v]){
            //printf("add:%d->%d=%d\n",u,v,w);
            add(u,v,w);
        }
        if(h[u]<=h[v]){
            //printf("add:%d->%d=%d\n",u,v,w);
            //printf("add:%d->%d=%d\n",v,u,w);
            add(v,u,w);
        }
    }
    //puts("---");
    bfs();
    //puts("");
    sort(s+1,s+num_edge2+1,cmp);

    // for(int i=1;i<=num_edge2;i++){
    //     printf("%d %d %d\n",s[i].from,s[i].to,s[i].dis);
    // }
    //puts("---");
    for(int i=1;i<=num_edge2;i++){
        if(!check(s[i].from,s[i].to)){
            unionn(s[i].from,s[i].to);
            //cnt++;
            sum+=s[i].dis;
        }
    }
    printf("%d %lld",num_edge,sum);
    return 0;
}