#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1e4,M=1e4;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int p=998244353;
using namespace std;
#define lson(xxx) (xxx)<<1
#define rson(xxx) (xxx)<<1|1
#define fmod(xxx) (xxx)>=mod ? (xxx)%mod : xxx
int n,m,r;
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
int son[N];//重儿子编号
int id[N];//新编号
int fa[N];//父亲节点
int cnt;//dfs序
int dep[N];//深度
int size[N];//子树大小
int top[N];//当前链顶端节点 
int w[N],wt[N];//初始点权数组 
int res;
int a[N<<2],lazy[N<<2];//线段树
void build(int rt,int l,int r){
    if(l==r){
        a[rt]=wt[l];
        a[rt]=fmod(a[rt]);
        return;
    }
    int mid=l+r>>1;
    build(lson(rt),l,mid);
    build(rson(rt),mid+1,r);
    a[rt]=(a[lson(rt)]+a[rson(rt)])%p;
}
inline void pushdown(int rt,int lenn){
    lazy[lson(rt)]+=lazy[rt];
    lazy[rson(rt)]+=lazy[rt];
    a[lson(rt)]+=lazy[rt]*(lenn-(lenn>>1));
    a[rson(rt)]+=lazy[rt]*(lenn>>1);
    a[lson(rt)]%=p;
    a[rson(rt)]%=p;
    lazy[rt]=0;
}
inline void query(int rt,int l,int r,int L,int R){
    int mid=l+r>>1;
    if(L<=l && r<=R){
        res+=a[rt];
        res%=p;
        return;
    }else{
        if(lazy[rt]){
            pushdown(rt,r-l+1);
        }
        if(L<=mid){
            query(lson(rt),l,mid,L,R);
        }
        if(R>mid){
            query(rson(rt),mid+1,r,L,R);
        }
    }
}
inline void update(int rt,int l,int r,int L,int R,int k){
    int mid=l+r>>1;
    if(L<=l && r<=R){
        lazy[rt]+=k;
        a[rt]+=k*(r-l+1);
    }else{
        if(lazy[rt]){
            pushdown(rt,r-l+1);
        }
        if(L<=mid){
            update(lson(rt),l,mid,L,R,k);
        }
        if(r>mid){
            update(rson(rt),mid+1,r,L,R,k);
        }
        a[rt]=(a[lson(rt)]+a[rson(rt)])%p;
    }
}
inline int qrange(int x,int y){
    int ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]){
            swap(x,y);
        }
        res=0;
        query(1,1,n,id[top[x]],id[x]);
        ans+=res;
        ans%=p;
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]){
        swap(x,y);
    }
    res=0;
    query(1,1,n,id[x],id[y]);
    ans+=res;
    return ans%p;
}
inline void updRange(int x,int y,int k){
    
}
int main(){
    
    return 0;
}