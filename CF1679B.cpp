#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (200005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,q;
int a[N];
struct T{
    int val,tag;
    int l,r;
}t[N<<2];
inline void upload(int p){
    t[p].val=t[ls(p)].val+t[rs(p)].val;
}
inline void spread(int p){
    if(t[p].tag){
        t[ls(p)].val=t[p].tag*(t[ls(p)].r-t[ls(p)].l+1);
        t[rs(p)].val=t[p].tag*(t[rs(p)].r-t[rs(p)].l+1);
        t[ls(p)].tag=t[rs(p)].tag=t[p].tag;
        t[p].tag=0;
    }
}
void build(int p,int l,int r){
    t[p].l=l,t[p].r=r;
    if(l==r){
        t[p].val=a[l];
        return;
    }
    int mid=l+r>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    upload(p);
}
void update(int p,int l,int r,int v){
    if(l<=t[p].l && r>=t[p].r){
        t[p].val=v*(t[p].r-t[p].l+1);
        t[p].tag=v;
        return;
    }
    spread(p);
    int mid=t[p].l+t[p].r>>1;
    if(l<=mid) update(ls(p),l,r,v);
    if(r>mid) update(rs(p),l,r,v);
    upload(p);
}
int query(int p,int l,int r){
    if(l<=t[p].l && r>=t[p].r){
        return t[p].val;
    }
    spread(p);
    int mid=t[p].l+t[p].r>>1;
    int ans=0;
    if(l<=mid) ans+=query(ls(p),l,r);
    if(r>mid) ans+=query(rs(p),l,r);
    return ans;
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    while(q--){
        int opt,t; scanf("%d %d",&opt,&t);
        if(opt==1){
            int x; scanf("%d",&x);
            update(1,t,t,x);
        }else{
            update(1,1,n,t);
        }
        printf("%d\n",query(1,1,n));
    }
    return 0;
}