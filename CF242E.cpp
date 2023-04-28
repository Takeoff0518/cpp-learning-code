#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
const int N=100005,M=1005;
const int INF=0x3f3f3f3f;
const int mod=998244353;
using namespace std;
struct T{
	ll val[32],laz;
	int l,r;
}t[N<<2];
int a[N];
void pushdown(int p){
	for(int i=0;i<32;i++){
		t[p].val[i]=t[ls(p)].val[i]+t[rs(p)].val[i];
	}
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		for(int i=0;i<32;i++){
			if((a[l]>>i)&1) t[p].val[i]++;
		}
		return;
	}
	int mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	pushdown(p);
}
int spread(int p){
	if(t[p].laz){
		int mid=t[p].l+t[p].r>>1;
		for(int i=0;i<32;i++){
			if((t[p].laz>>i)&1){
				t[ls(p)].val[i]=(mid-t[p].l+1)-t[ls(p)].val[i];
				t[rs(p)].val[i]=(t[p].r-mid)-t[rs(p)].val[i];
			}
		}
	}
	t[ls(p)].laz^=t[p].laz;
	t[rs(p)].laz^=t[p].laz;
	t[p].laz=0;
}
void update(int p,int l,int r,ll v){
	if(l<=t[p].l && r>=t[p].r){
		for(int i=0;i<30;i++){
			if((v>>i)&1){
				t[p].val[i]=(t[p].r-t[p].l+1)-t[p].val[i];
			}
		}
		t[p].laz^=v;
		return;
	}
	spread(p);
	int mid=t[p].l+t[p].r>>1;
	if(l<=mid) update(ls(p),l,r,v);
	if(r>mid) update(rs(p),l,r,v);
	pushdown(p);
}
ll query(int p,int l,int r){
	if(l<=t[p].l && r>=t[p].r){
		ll ans=0;
		for(int i=0;i<30;i++){
			ans+=(t[p].val[i])*(1<<i);
		}
		return ans;
	}
	spread(p);
	ll ans=0; int mid=t[p].l+t[p].r>>1;
	if(l<=mid) ans+=query(ls(p),l,r);
	if(r>mid) ans+=query(rs(p),l,r);
	return ans;
}
int n,m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int opt,l,r;
		scanf("%d %d %d",&opt,&l,&r);
		if(opt==1){
			printf("%lld\n",query(1,l,r));
		}else{
			ll v;
			scanf("%lld",&v);
			update(1,l,r,v); 
		}
	} 
    return 0;
}
//F**k CCF!!!!!

