#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (100005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
struct T{
    int l,r;
    ll val,tag;
}t[N<<2];
int n,a[N],m;
inline void upload(int p){
    t[p].val=t[ls(p)].val+t[rs(p)].val;
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
void spread(int p){
    if(t[p].tag){
        t[ls(p)].val+=t[p].tag*(t[ls(p)].r-t[ls(p)].l+1);
        t[rs(p)].val+=t[p].tag*(t[rs(p)].r-t[rs(p)].l+1);
        t[ls(p)].tag+=t[p].tag;
        t[rs(p)].tag+=t[p].tag;
        t[p].tag=0;
    }
}
void update(int p,int l,int r,int v){
    // printf("%d %d %d %d\n",p,l,r,v);
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
/*
void upd(int p,int l,int r,int v){
    // printf("%d %d %d %d\n",p,l,r,v);
    if(l<=t[p].l && r>=t[p].r){
        // puts("oops!");
        t[p].val+=v*(t[p].r-t[p].l+1);
        t[p].tag+=v;
        return;
    }
    spread(p);
    int mid=t[p].l+t[p].r>>1;
    if(l<=mid) upd(ls(p),l,r,v);
    if(r>mid) upd(rs(p),l,r,v);
   
*/
ll query(int p,int l,int r){
    // printf("%d %d %d\n",p,l,r);
    if(l<=t[p].l && r>=t[p].r){
        return t[p].val;
    }
    spread(p);
    ll ans=0; int mid=t[p].l+t[p].r>>1;
    if(l<=mid) ans+=query(ls(p),l,r);
    if(r>mid) ans+=query(rs(p),l,r);
    return ans;
}
/*
ll query(int p,int l,int r){
    if(l<=t[p].l && r>=t[p].r){
        return t[p].val;
    }
    spread(p);
    int mid=t[p].l+t[p].r>>1;
    ll ans=0;
    if(l<=mid) ans+=query(ls(p),l,r);
    if(r>mid) ans+=query(rs(p),l,r);
    return ans; 
}
*/
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    while(m--){
        int opt,x,y; scanf("%d %d %d",&opt,&x,&y);
        if(opt==1){
            int k;
            scanf("%d",&k);
            update(1,x,y,k);
        }else{
            printf("%lld\n",query(1,x,y));
        }
    }
    return 0;
}