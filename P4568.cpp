#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define INF 0x3f3f3f3f
#define ll long long
#define N 110005
#define M 2500005
using namespace std;
struct E{
    int nxt,to,v;
}edge[M];
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
int dis[N];
bool vis[N];
int n,m,n,s,t;
void dijkstra(){
    //n*=(k+1);
    memset(dis,INF,sizeof(dis));
    dis[s]=0;
    q.push((node){0,s});
    while(!q.empty()){
        node tmp=q.top();
        q.pop();
        int min_i=tmp.pos,min_dis=tmp.dis;
        if(vis[min_i]){
            continue;
        }
        vis[min_i]=1;
        for(int i=head[min_i];i;i=edge[i].nxt){
            int p=edge[i].to;
            if(dis[p]>dis[min_i]+edge[i].v){
                dis[p]=dis[min_i]+edge[i].v;
            }
            if(!vis[p]){
                q.push((node){dis[p],p});
            }
        }
    }
}
int main(){
    scanf("%d %d %d %d %d",&n,&m,&n,&s,&t);
    //s++,t++;
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        //a++,b++;
        add(a,b,c);
        add(b,a,c);
        for(int j=1;j<=n;j++){
            add(a+j*n,b+j*n,c);
            add(b+j*n,a+j*n,c);

            add(a+n*(j-1),b+n*j,0);
            add(b+n*(j-1),a+n*j,0);
            
        }
    }
    for(int i=1;i<=n;i++){
        add(t+(i-1)*n,t+i*n,0);
    }
    dijkstra();
    // for(int i=1;i<=n;i++){
    //     printf("%d ",dis[i]);
    // }
    // puts("");
    printf("%d\n",dis[t+n*n]);
    return 0;
}