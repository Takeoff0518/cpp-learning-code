#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 10005
#define M 10005
#define int ll
using namespace std;
#define lson(_) (_*2)
#define rson(_) (_*2+1)
int a[N],n,m;
struct tree{
    int l,r;
    ll data,lazy;
}t[4*N];
void build(int p,int l,int r){
    t[p].l=l,t[p].r=r;
    if(l==r){
        t[p].data=a[l];
        return;
    }
    int mid=l+r>>1;
    build(lson(p),l,mid);
    build(rson(p),mid+1,r);
    t[p].data=t[lson(p)].data+t[rson(p)].data;
}
void spread(int p){
    if(t[p].lazy){
        t[lson(p)].data+=(ll)t[p].lazy*(t[lson(p)].r-t[lson(p)].l+1);
        t[rson(p)].data+=(ll)t[p].lazy*(t[rson(p)].r-t[rson(p)].l+1);
        t[lson(p)].lazy+=(ll)t[p].lazy;
        t[rson(p)].lazy+=(ll)t[p].lazy;
        t[p].lazy=0;
    }
}
void update(int p,int l,int r,int v){
    if(l<=t[p].l && r>=t[p].r){
        t[p].data+=(ll)v*(t[p].r-t[p].l+1);
        t[p].lazy+=v;
        return;
    }
    spread(p);
    int mid=t[p].l+t[p].r>>1;
    if(l<=mid){
        update(lson(p),l,r,v);
    }
    if(r>mid){
        update(rson(p),l,r,v);
    }
    t[p].data=t[lson(p)].data+t[rson(p)].data;
}
ll query(int p,int l,int r){
    if(l<=t[p].l && r>=t[p].r){
        return t[p].data;
    }
    spread(p);
    int mid=t[p].l+t[p].r>>1;
    int ans=0;
    if(l<=mid){
        ans+=query(lson(p),l,r);
    }
    if(r>mid){
        ans+=query(rson(p),l,r);
    }
    return ans;
}
signed main(){
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    build(1,1,n);
    int opt,x,y,k;
    while(m--){
        scanf("%lld",&opt);
        switch(opt){
            case 1:
                scanf("%lld %lld %ld",&x,&y,&k);
                update(1,x,y,k);
                break;
            case 2:
                scanf("%lld %lld",&x,&y);
                printf("%lld\n",query(1,x,y));
                break;
        }
    }
    return 0;
}
