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
int n,m;
double a[N];
struct T{
    int l,r;
    double sum,sqr;
    double tag;
}t[N<<2];
inline void upload(int p){
    t[p].sum=t[ls(p)].sum+t[rs(p)].sum;
    t[p].sqr=t[ls(p)].sqr+t[rs(p)].sqr;
}
void build(int p,int l,int r){
    if(l==r){
        t[p].sum=a[l];
        t[p].sqr=a[l]*a[l];
        return;
    }
    t[p].l=l,t[p].r=r;
    int mid=l+r>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
}
void spread(int p){
    if(t[p].tag!=0){
        t[ls(p)].sum+=t[p].tag*(t[ls(p)].r-t[ls(p)].l+1);
        t[rs(p)].sum+=t[p].tag*(t[rs(p)].r-t[rs(p)].l+1);
        t[ls(p)].sqr+=2*t[p].tag*t[ls(p)].sum+(t[ls(p)].r-t[ls(p)].l+1)*t[p].tag*t[p].tag;
        t[rs(p)].sqr+=2*t[p].tag*t[rs(p)].sum+(t[rs(p)].r-t[rs(p)].l+1)*t[p].tag*t[p].tag;
        t[ls(p)].tag+=t[p].tag;
        t[rs(p)].tag+=t[p].tag;
        t[p].tag=0;
    }
}
void update(int p,int l,int r,double v){
    if(l<=t[p].l && r>=t[p].r){
        t[p].sqr+=2*v*t[p].sum+(t[p].r-t[p].l+1)*v*v;
        t[p].sum+=v*(t[p].r-t[p].l+1);
        t[p].tag+=v;
        return;
    }
    spread(p);
    int mid=t[p].l+t[p].r>>1;
    if(l<=mid) update(ls(p),l,r,v);
    if(r>mid) update(rs(p),l,r,v);
    upload(p);
}
double query1(int p,int l,int r){ //sum
    // printf("rt:%d\n",p);
    if(l<=t[p].l && r>=t[p].r){
        return t[p].sum;
    }
    double ans=0;
    spread(p);
    int mid=t[p].l+t[p].r>>1;
    // printf("%d %d %d\n",mid,t[p].l,t[p].r);
    if(l<=mid) ans+=query1(ls(p),l,r);
    if(r>mid) ans+=query1(rs(p),l,r);
    return ans;
}
double query2(int p,int l,int r){ //sqr
    if(l<=t[p].l && r>=t[p].r){
        return t[p].sqr;
    }
    double ans=0;
    int mid=t[p].l+t[p].r>>1;
    if(l<=mid) ans+=query2(ls(p),l,r);
    if(r>mid) ans+=query2(rs(p),l,r);
    return ans;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lf",&a[i]);
    }
    build(1,1,n);
    while(m--){
        int opt,x,y;
        scanf("%d %d %d",&opt,&x,&y);
        switch(opt){
            case 1:
                double k;
                scanf("%lf",&k);
                update(1,x,y,k);
                break;
            case 2:
                printf("%.4lf\n",query1(1,x,y)/(y-x+1));
                break;
            case 3:
                printf("%.4lf\n",-query1(1,x,y)+query2(1,x,y)/(y-x+1));
                break;
        }
    }
    return 0;
}