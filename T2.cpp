#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
const int N=10005,M=100005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m;
string typ[N];
struct E{
    int nxt,to,v;
}edge[2*M];
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
int dis[N];
bool vis[N];
void djikstra(int s){
    priority_queue<node> q;
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    q.push((node){s,0});
    while(!q.empty()){
        int min_i=q.top().pos;
        q.pop();
        if(vis[min_i]){
            continue;
        }
        vis[min_i]=1;
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
bool sp1=1,sp2,sp3;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>typ[i];
        if(sp1 && i>=2){
            if(typ[i]!=typ[i-1])
                sp1=0;
        }
    }
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        add(u,v,w),add(v,u,w);
    }
    if(sp1){
        djikstra(1);
        cout<<"1 "<<dis[n];
        return 0;
    }
    return 0;
}