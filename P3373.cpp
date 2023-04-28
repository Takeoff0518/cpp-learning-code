#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
const int N=1e5+5,M=1005;
const ll INF=1e18;
//const int mod=998244353;
using namespace std;
int n,m;
ll mod,a[N];
struct T{
	ll val,tag1,tag2;
	int l,r;
	//1-* 2-+
}t[N<<2];
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r,t[p].tag1=1;
	if(l==r){
		t[p].val=a[l]%mod;
		return;
	}
	int mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	t[p].val=(t[ls(p)].val+t[rs(p)].val)%mod;
	//cout<<l<<' '<<r<<' '<<t[p].val<<endl;
}
void spread(int p){
	t[ls(p)].val=(t[p].tag1*t[ls(p)].val+(ll)t[p].tag2*(t[ls(p)].r-t[ls(p)].l+1))%mod;
	t[rs(p)].val=(t[p].tag1*t[rs(p)].val+(ll)t[p].tag2*(t[rs(p)].r-t[rs(p)].l+1))%mod;
	t[ls(p)].tag1=(t[p].tag1*t[ls(p)].tag1)%mod;
	t[rs(p)].tag1=(t[p].tag1*t[rs(p)].tag1)%mod;
	t[ls(p)].tag2=(t[p].tag1*t[ls(p)].tag2+t[p].tag2)%mod;
	t[rs(p)].tag2=(t[p].tag1*t[rs(p)].tag2+t[p].tag2)%mod;
	t[p].tag1=1,t[p].tag2=0;
}
void update(int p,int l,int r,ll v,int opt){
	if(l<=t[p].l && r>=t[p].r){
		if(opt==1){
			t[p].tag2=(t[p].tag2*v)%mod;
			t[p].tag1=(t[p].tag1*v)%mod;
			t[p].val=(t[p].val*v)%mod;
		}else{
			t[p].val=(t[p].val+(ll)v*(t[p].r-t[p].l+1))%mod;
			t[p].tag2=(t[p].tag2+v)%mod;
		}
		return;
	}
	spread(p);
	int mid=t[p].l+t[p].r>>1;
	if(l<=mid) update(ls(p),l,r,v,opt);
	if(r>mid) update(rs(p),l,r,v,opt);
	t[p].val=(t[ls(p)].val+t[rs(p)].val)%mod;
}
ll query(int p,int l,int r){
	if(l<=t[p].l && r>=t[p].r){
		return t[p].val;
	}
	spread(p);
	int mid=t[p].l+t[p].r>>1;
	ll ans=0;
	if(l<=mid) ans=(ans+query(ls(p),l,r))%mod;
	if(r>mid) ans=(ans+query(rs(p),l,r))%mod;
	return ans;
}
int main(){
	scanf("%d %d %lld",&n,&m,&mod);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	build(1,1,n);
//	for(int i=1;i<=(n<<2);i++){
//		printf("%lld ",t[i].val);
//	}
//	puts("");
	for(int i=1;i<=m;i++){
		int opt,x,y;
		scanf("%d %d %d",&opt,&x,&y);
		if(opt==1 || opt==2){
			ll k;
			scanf("%lld",&k);
			update(1,x,y,k,opt);
		}else{
			printf("%lld\n",query(1,x,y));
		}
	}
    return 0;
}
//F**k CCF!!!!!

