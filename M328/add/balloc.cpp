#pragma GCC optimize(2)
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
int a[N];
PII d[N];
struct T{
	int val,tag;
	int l,r;
	T(){ val=INF;}
}t[N<<2];
void upload(int p){
	t[p].val=min(t[ls(p)].val,t[rs(p)].val);
}
void spread(int p){
	if(t[p].tag){
		t[ls(p)].val+=t[p].tag;
		t[rs(p)].val+=t[p].tag;
		t[ls(p)].tag+=t[p].tag;
		t[rs(p)].tag+=t[p].tag;
		t[p].tag=0;
	}
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].val=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	upload(p);
}
void update(int p,int l,int r,int v){
	if(l<=t[p].l && r>=t[p].r){
		t[p].val+=v;
		t[p].tag+=v;
		return;
	}
	spread(p);
	int mid=(t[p].l+t[p].r)>>1;
	if(l<=mid) update(ls(p),l,r,v);
	if(r>mid) update(rs(p),l,r,v);
	upload(p); 
}
int query(int p,int l,int r){
	if(l<=t[p].l && r>=t[p].r){
		return t[p].val;
	}
	spread(p);
	int ans=INF,mid=(t[p].l+t[p].r)>>1;
	if(l<=mid) ans=min(ans,query(ls(p),l,r));
	if(r>mid) ans=min(ans,query(rs(p),l,r));
	return ans;
}
int main(){
	freopen("balloc.in","r",stdin),freopen("balloc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++) scanf("%d %d",&d[i].first,&d[i].second);
	sort(d+1,d+m+1,[](PII xxx,PII yyy){	return xxx.second<yyy.second;});
	int ans=0;
	for(int i=1;i<=m;i++){
		int l=d[i].first,r=d[i].second;
		if(query(1,l,r)){
			update(1,l,r,-1);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
/*
	zyb txdy!
	Author: takeoff37808
*/

