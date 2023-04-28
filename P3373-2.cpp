#include <bits/stdc++.h>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
#define MAXN 100010
#define ll long long

using namespace std;

int n,m,p;
int a[MAXN];

struct Segment_Tree {
	ll val,tag2,tag1;
	int l,r;
}t[MAXN*4];

void update(int p) {
	t[p].val=(t[ls(p)].val+t[rs(p)].val)%p;
    return;
}

void pushdown(int p) { //pushdown的维护
	t[ls(p)].val=(t[ls(p)].val*t[p].tag1+t[p].tag2*(t[ls(p)].r-t[ls(p)].l+1))%p;
	t[rs(p)].val=(t[rs(p)].val*t[p].tag1+t[p].tag2*(t[rs(p)].r-t[rs(p)].l+1))%p;
	
	t[ls(p)].tag1=(t[ls(p)].tag1*t[p].tag1)%p;
	t[rs(p)].tag1=(t[rs(p)].tag1*t[p].tag1)%p;
	
	t[ls(p)].tag2=(t[ls(p)].tag2*t[p].tag1+t[p].tag2)%p;
	t[rs(p)].tag2=(t[rs(p)].tag2*t[p].tag1+t[p].tag2)%p;
		
	t[p].tag2=0;
	t[p].tag1=1;
	return; 
}

void build(int pos,int l,int r) { //建树
	t[pos].l=l;
	t[pos].r=r;
	t[pos].tag1=1;
	
	if (l==r) {
		t[pos].val=a[l]%p;
		return;
	}
	
	int mid=(l+r)>>1;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	update(pos);
	return;
}

void ChangeMul(int pos,int x,int y,int k) { //区间乘法
	if (x <= t[pos].l && t[pos].r <= y) {
		t[pos].tag2=(t[pos].tag2*k)%p;
		t[pos].tag1=(t[pos].tag1*k)%p;
		t[pos].val=(t[pos].val*k)%p;
		return;
	}
	
	pushdown(pos);
	int mid=(t[pos].l+t[pos].r)>>1;
	if (x <= mid) ChangeMul(ls(pos),x,y,k);
	if (y > mid) ChangeMul(rs(pos),x,y,k);
	update(pos);
	return;
}

void ChangeAdd(int pos,int x,int y,int k) { //区间加法
	if (x <= t[pos].l && t[pos].r <= y) {
		t[pos].tag2=(t[pos].tag2+k)%p;
		t[pos].val=(t[pos].val+k*(t[pos].r-t[pos].l+1))%p;
		return;
	}
	
	pushdown(pos);
	int mid=(t[pos].l+t[pos].r)>>1;
	if (x <= mid) ChangeAdd(ls(pos),x,y,k);
	if (y > mid) ChangeAdd(rs(pos),x,y,k);
	update(pos);
	return;
}

ll AskRange(int pos,int x,int y) { //区间询问
	if (x <= t[pos].l && t[pos].r <= y) {
		return t[pos].val;
	}
	
	pushdown(pos);
	ll val=0;
	int mid=(t[pos].l+t[pos].r)>>1;
	if (x <= mid) val=(val+AskRange(ls(pos),x,y))%p;
	if (y > mid) val=(val+AskRange(rs(pos),x,y))%p;
	return val;
}

int main() {
	scanf("%d%d%d",&n,&m,&p);
	
	for (int i=1; i <= n; i++) {
		scanf("%d",&a[i]);
	}
	
	build(1,1,n);
	
	for (int i=1; i <= m; i++) {
		int opt,x,y;
		scanf("%d%d%d",&opt,&x,&y);
		if (opt==1) {
			int k;
			scanf("%d",&k);
			ChangeMul(1,x,y,k);
		}
		if (opt==2) {
			int k;
			scanf("%d",&k);
			ChangeAdd(1,x,y,k);
		}
		if (opt==3) {
			printf("%lld\n",AskRange(1,x,y));
		}
	}
    
	return 0;
}
