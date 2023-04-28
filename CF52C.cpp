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
int a[N],space,n,m;
struct T{
    int l,r,val,tag;
}t[N<<2];
inline void upl(int p){
    t[p].val=min(t[ls(p)].val,t[rs(p)].val);
}
ll read(){
	ll res=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1; c=getchar();}
	while (isdigit(c))res=res*10+c-48,c=getchar();
	if(c==' ') space++;
	return res*f;
}
void build(int p,int l,int r){
    t[p].l=l,t[p].r=r;
    t[p].val=INF;
    if(l==r){
        t[p].val=a[l];
        return;
    }
    int mid=l+r>>1;
    build(ls(p),1,mid);
    build(rs(p),mid+1,r);
    upl(p);
}
inline void spr(int p){
    if(t[p].tag){
        t[ls(p)].val+=t[p].tag;
        t[rs(p)].val+=t[p].tag;
        t[ls(p)].tag+=t[p].tag;
        t[rs(p)].tag+=t[p].tag;
        t[p].tag=0;
    }
}
void upd(int p,int l,int r,int v){
    if(l<=t[p].l && r>=t[p].r){
        t[p].tag+=v;
        t[p].val+=v;
        return;
    }
    spr(p);
    int mid=t[p].l+t[p].r>>1;
    if(l<=mid) upd(ls(p),l,r,v);
    if(r>mid) upd(rs(p),l,r,v);
    upl(p);
} 
int que(int p,int l,int r){
    if(l<=t[p].l && r>=t[p].r){
        return t[p].val;
    }
    spr(p);
    int mid=t[p].l+t[p].r>>1,ans=INF;
    if(l<=mid) ans=min(ans,que(ls(p),l,r));
    if(r>mid) ans=min(ans,que(rs(p),l,r));
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    scanf("%d",&m);
    while(m--){
        int l,r; l=read(); r=read(); l++,r++;
        if(space==2){
            int k; k=read();
            if(l<=r) upd(1,l,r,k);
            else{ upd(1,1,r,k); upd(1,l,n,k);}
        }else{
            if(l<=r) printf("%d\n",que(1,l,r));
            else printf("%d\n",min(que(1,1,r),que(1,l,n)));
        }
        space=0;
    }
    return 0;
}