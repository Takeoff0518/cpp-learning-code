#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
const int N=200005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int a[N],n,m;
struct T{
	int l,r,val,lazy;
}t[4*N];
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
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
	if(t[p].lazy!=-1){
		t[ls(p)].val=max(t[ls(p)].val,t[p].lazy);
		t[rs(p)].val=max(t[rs(p)].val,t[p].lazy);
		t[ls(p)].lazy=max(t[ls(p)].lazy,t[p].lazy);
		t[rs(p)].lazy=max(t[rs(p)].lazy,t[p].lazy);
		t[p].lazy=-1;
	}
}
void update(int p,int l,int r,int v){
	if(l<=t[p].l && r>=t[p].r){
		t[p].val=max(t[p].val,v);
		t[p].lazy=max(t[p].lazy,v);
		return;
	}
	spread(p);
	int mid=t[p].l+t[p].r>>1;
	if(l<=mid) update(ls(p),l,r,v);
	if(r>mid) update(rs(p),l,r,v);
	t[p].val=max(t[ls(p)].val,t[rs(p)].val);
}
int query(int p,int l,int r){
	if(l<=t[p].l && r>=t[p].r){
		return t[p].val; 
	}
	spread(p);
	int mid=t[p].l+t[p].r>>1,ans=-1;
	if(l<=mid) ans=max(ans,query(ls(p),l,r));
	if(r>mid) ans=max(ans,query(rs(p),l,r));
	return ans;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	for(int i=1;i<=m;i++){
		char opt[3];
		int x,y;
		scanf("%s %d %d",opt,&x,&y);
		if(opt[0]=='Q') printf("%d\n",query(1,x,y));
		else update(1,x,x,y);
	}
    return 0;
}
//F**k CCF!!!!!

