#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
const int N=1000005,M=1005;
const ll INF=1e18;
const int mod=998244353;
using namespace std;
int n,m,a[N];
int read(){
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
struct T{
	ll val,laz1,laz2;
	bool used;
	int l,r;
}t[N<<2];
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	t[p].val=-INF;
	if(l==r){
		t[p].val=a[l];
		return;
	}
	int mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	t[p].val=max(t[ls(p)].val,t[rs(p)].val);
}
void spread(int p){
	if(t[p].used){
		t[ls(p)].laz1=(ll)t[p].laz1;
		t[rs(p)].laz1=(ll)t[p].laz1;
		t[ls(p)].laz2=(ll)t[p].laz2;
		t[rs(p)].laz2=(ll)t[p].laz2;
		t[ls(p)].val=t[p].laz1+t[p].laz2;
		t[rs(p)].val=t[p].laz1+t[p].laz2;
		t[ls(p)].used=t[rs(p)].used=1;
	}else{
		t[ls(p)].laz2+=t[p].laz2;
		t[rs(p)].laz2+=t[p].laz2;
		t[ls(p)].val+=(ll)t[p].laz2;
		t[rs(p)].val+=(ll)t[p].laz2;
	}
	t[p].used=t[p].laz1=t[p].laz2=0;
}
void update(int p,int l,int r,ll v,int opt){
	if(l<=t[p].l && r>=t[p].r){
		if(opt==1){
			t[p].val=v;
			t[p].laz1=v;
			t[p].laz2=0;
			t[p].used=1;
		}else{
			t[p].val+=v;
			t[p].laz2+=v;
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
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int opt,l,r;
		ll x;
		scanf("%d %d %d",&opt,&l,&r);
		if(opt==1){
			scanf("%lld",&x);
			update(1,l,r,x,1);
		}else if(opt==2){
			scanf("%lld",&x);
			update(1,l,r,x,2);
		}else{
			ll ans=query(1,l,r);
			printf("%lld\n",ans);
		}
		
	}
    return 0;
}
//F**k CCF!!!!!