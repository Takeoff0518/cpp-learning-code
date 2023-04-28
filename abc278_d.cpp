#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (200005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
struct T{
	int l,r;
	ll laz1,laz2,val;
}t[N<<2];
int a[N];
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].val=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	t[p].val=t[ls(p)].val+t[rs(p)].val;
}
void spread(int p){
	if(t[p].laz1){
		t[ls(p)].val=(ll)t[p].laz1*(t[ls(p)].r-t[ls(p)].l+1);
		t[rs(p)].val=(ll)t[p].laz1*(t[rs(p)].r-t[rs(p)].l+1);
		t[ls(p)].laz1=t[p].laz1;
		t[rs(p)].laz1=t[p].laz1;
		t[ls(p)].laz2=t[rs(p)].laz2=0;
		t[p].laz1=t[p].laz2=0;
	}
	if(t[p].laz2){
		t[ls(p)].val+=(ll)t[p].laz2*(t[ls(p)].r-t[ls(p)].l+1);
		t[rs(p)].val+=(ll)t[p].laz2*(t[rs(p)].r-t[rs(p)].l+1);
		t[ls(p)].laz2+=t[p].laz2;
		t[rs(p)].laz2+=t[p].laz2;
		t[p].laz2=0;
	}
}
void update(int p,int l,int r,ll v,int opt){
	if(l<=t[p].l && r>=t[p].r){
		if(opt==1){
			t[p].laz2=0;
			t[p].laz1=v;
			t[p].val=(ll)v*(t[p].r-t[p].l+1);
		}else{
			t[p].laz1=0;
			t[p].laz2+=v;
			t[p].val+=(ll)v*(t[p].r-t[p].l+1);
		}
		return;
	}
	spread(p);
	int mid=t[p].l+t[p].r>>1;
	if(l<=mid) update(ls(p),l,r,v,opt);
	if(r>mid) update(rs(p),l,r,v,opt);
	t[p].val=t[ls(p)].val+t[rs(p)].val;
}
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
int n,m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int opt,x,y;
		scanf("%d %d",&opt,&x);
		if(opt==3){
			ll ans=query(1,x,x);
			printf("%lld\n",ans);
		} 
		else if(opt==1) update(1,1,n,x,1);
		else{
			scanf("%d",&y);
			update(1,x,x,y,2);
		}
	}
    return 0;
}
//F**k CCF!!!!!

