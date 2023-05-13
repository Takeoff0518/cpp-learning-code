#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
// #define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int mod;
int fa[N];//父节点
int dep[N];//深度
int son[N];//重儿子
int siz[N];//大小
int timestamp;//时间戳
int top[N];//重链顶部
int id[N];//时间戳
int w[N];//结点权值dfs序
int v[N];
struct E{
    int nxt,to;
}edge[M];
struct T{
    int val,tag;
    int l,r;
}t[N<<2];
int head[N],num_edge;
/*线段树*/
void add(int from,int to){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    head[from]=num_edge;
}
inline void upload(int p){
    t[p].val=t[ls(p)].val+t[rs(p)].val;
}
inline void spread(int p){
    if(t[p].tag){
        t[ls(p)].val=(t[ls(p)].val+t[p].tag*(t[ls(p)].r-t[ls(p)].l+1))%mod;
        t[rs(p)].val=(t[rs(p)].val+t[p].tag*(t[rs(p)].r-t[rs(p)].l+1))%mod;
        t[ls(p)].tag+=t[p].tag;
        t[rs(p)].tag+=t[p].tag;
        t[p].tag=0;
    }
}
void build(int p,int l,int r){
    t[p].l=l,t[p].r=r;
    if(l==r){
        t[p].val=w[l];
        return;
    }
    int mid=l+r>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    upload(p);
}
int query(int p,int l,int r){
    if(l<=t[p].l && r>=t[p].r){
        return t[p].val;
    }
    spread(p);
    int mid=t[p].l+t[p].r>>1,ans=0;
    if(l<=mid) ans+=query(ls(p),l,r);
    if(r>mid) ans+=query(rs(p),l,r);
    return ans;
}
void update(int p,int l,int r,int v){
    if(l<=t[p].l && r>=t[p].r){
        t[p].val+=v*(t[p].r-t[p].l+1);
        t[p].tag+=v;
        return;
    }
    spread(p);
    int mid=t[p].l+t[p].r>>1;
    if(l<=mid) update(ls(p),l,r,v);
    if(r>mid) update(rs(p),l,r,v);
    upload(p);
}
/*树剖预处理*/

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

//t重链顶端
void dfs2(int u,int t){
    timestamp++;
    id[u]=timestamp;
    top[u]=t;
    w[timestamp]=v[u];
    if(!son[u]) return;//没儿子
    dfs2(son[u],t);//先往重儿子走
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fa[u] || v==son[u])//当前节点是父亲或者重儿子
            continue;
        dfs2(v,v);//轻儿子不属于当前重链，新开一条链
    }   
}
/*树剖查询*/
inline int qson(int x){
    return query(1,id[x],id[x]+siz[x]-1);
}
inline void updson(int x,int k){
    update(1,id[x],id[x]+siz[x]-1,k);
}
int qrange(int x,int y){
    int ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans=(ans+query(1,id[top[x]],id[x]))%mod;
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    ans=(ans+query(1,id[x],id[y]))%mod;
    return ans;
}
void updrange(int x,int y,int k){
    k%=mod;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        update(1,id[top[x]],id[x],k);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    update(1,id[x],id[y],k);
}
int n,m,r;
int main(){
    scanf("%d %d %d %d",&n,&m,&r,&mod);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1,u,v;i<n;i++){
        scanf("%d %d",&u,&v);
        add(u,v); add(v,u);
    }
    dfs1(r,0);
    dfs2(r,r);
    build(1,1,n);
    while(m--){
        int k,x,y,z;
        scanf("%d",&k);
        if(k==1){
            scanf("%d %d %d",&x,&y,&z);
            updrange(x,y,z);
        }else if(k==2){
            scanf("%d %d",&x,&y);
            printf("%d\n",qrange(x,y));
        }else if(k==3){
            scanf("%d %d",&x,&y);
            updson(x,y);
        }else{
            scanf("%d",&x);
            printf("%d\n",qson(x));
        }
    }
    return 0;
}