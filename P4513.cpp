#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int s[N]; 
struct T{
	ll sum,maxl,maxr,ans;
	int l,r;
}t[N<<2];
void pushdown(int p){
	t[p].sum=t[ls(p)].sum+t[rs(p)];
	t[p].maxl=max(t[ls(p)].maxl,t[ls(p)].sum+t[rs(p)].maxl);
	t[p].maxr=max(t[rs(p)].maxr,t[ls(p)].maxl+t[rs(p)].sum);
	t[p].ans=max({t[ls(p)].ans,t[rs(p)].ans,t[ls(p)].maxr+t[rs(p)].maxl});
}
void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].sum=t[p].maxl=t[p].maxr=t[p].ans;
		return;
	}	
	int mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	pushdown(p);
}

int main(){

    return 0;
}
//F**k CCF!!!!!

