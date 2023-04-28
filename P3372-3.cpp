#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define PII pair<int,int>
#define lson(xxx) (xxx)<<1
#define rson(xxx) (xxx)<<1|1
const int N=100005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
struct T{
	ll lazy,data;
	int l,r;
}t[4*N];
int a[N];
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].data=a[l];//1
		return;
	}
	int mid=l+r>>1;
	build(lson(p),l,mid);
	build(rson(p),mid+1,r);
	t[p].data=t[lson(p)].data+t[rson(p)].data;
}
void spread(int p){
	if(t[p].lazy){
		t[lson(p)].data+=(ll)t[p].lazy*(t[lson(p)].r-t[lson(p)].l+1);//2
		t[rson(p)].data+=(ll)t[p].lazy*(t[rson(p)].r-t[rson(p)].l+1);
		t[lson(p)].lazy+=(ll)t[p].lazy;
		t[rson(p)].lazy+=(ll)t[p].lazy;
		t[p].lazy=0;
	}
}
ll query(int p,int l,int r){
	if(l<=t[p].l && r>=t[p].r){
		return t[p].data;
	}
	int mid=t[p].l+t[p].r>>1;
	ll ans=0;
	spread(p);
	if(l<=mid){
		ans+=query(lson(p),l,r);
	} 
	if(r>mid){
		ans+=query(rson(p),l,r);
	}
	return ans;
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
	t[p].data=t[lson(p)].data+t[rson(p)].data;//3
}
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int opt,x,y;
		scanf("%d %d %d",&opt,&x,&y);
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
//F**k CCF!!!!!

