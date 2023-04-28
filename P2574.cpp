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
int n,m;
bool a[N];
char s[N];
struct T{
	int l,r,val;
	bool lazy;
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
	t[p].val=t[ls(p)].val+t[rs(p)].val;
}
void spread(int p){
	if(t[p].lazy){
		t[ls(p)].val=(t[ls(p)].r-t[ls(p)].l+1)-t[ls(p)].val;
		t[rs(p)].val=(t[rs(p)].r-t[rs(p)].l+1)-t[rs(p)].val;
		t[ls(p)].lazy=!t[ls(p)].lazy;
		t[rs(p)].lazy=!t[rs(p)].lazy;
		t[p].lazy=0;
	}
}
int query(int p,int l,int r){
	if(l<=t[p].l && r>=t[p].r){
		return t[p].val;
	}
	spread(p);
	int mid=t[p].l+t[p].r>>1,ans=0;
	if(l<=mid) ans+=query(ls(p),l,r);
	if(r>mid) ans+=query(rs(p),l,r);
	return ans;
}
void update(int p,int l,int r){
	if(l<=t[p].l && r>=t[p].r){
		t[p].val=(t[p].r-t[p].l+1)-t[p].val;
		t[p].lazy=!t[p].lazy;
		return;
	}
	spread(p);
	int mid=t[p].l+t[p].r>>1;
	if(l<=mid) update(ls(p),l,r);
	if(r>mid) update(rs(p),l,r);
	t[p].val=t[ls(p)].val+t[rs(p)].val;
}
int main(){
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='1') a[i]=1;
	}
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int opt,x,y;
		scanf("%d %d %d",&opt,&x,&y);
		if(opt==0) update(1,x,y);
		else printf("%d\n",query(1,x,y)); 
	}
    return 0;
}
//F**k CCF!!!!!

