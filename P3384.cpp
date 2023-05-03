#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
struct E{
    int nxt,to,dis;
}edge[M];
int head[N],num_edge;
void add(int from,int to,int dis){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    edge[num_edge].dis=dis;
    head[from]=num_edge;
}
int fa[N];//父节点
int dep[N];//深度
int son[N];//重儿子
int siz[N];//大小
//u当前节点，f当前节点的父亲
void dfs1(int u,int f){
    fa[u]=f;
    dep[u]=dep[f]+1;
    siz[u]=1;
    int maxsize=-1;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==f) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>maxsize){
            maxsize=siz[v];
            son[u]=v;
        }
    }
}
int timestamp;//时间戳
int top[N];//重链顶部
int dfn[N];//时间戳
int w[N];//结点权值dfs序
int v[N];
void dfs2(int u,int t){
    timestamp++;
    dfn[u]=timestamp;
    top[u]=t;
    w[timestamp]=v[u];
}
int main(){
    
    return 0;
}