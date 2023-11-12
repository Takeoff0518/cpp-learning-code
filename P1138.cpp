#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (30005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,k;
int tong[N];
struct T{
	int l,r,val;
}t[N<<2];
inline void build(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].val=tong[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	t[p].val=t[ls(p)].val+t[rs(p)].val;
}
/*
	core:
	��ÿ���ڵ�ʱ��������������ܺʹ��ڵ���k��
	˵����k��ֵ�������������У���ݹ����������
	����˵����ʱ�ĵ�k��ֵ���������У���ݹ����������
	ע�⣺��ʱҪ��k��ֵ��ȥ���������ܺ͡�
*/
int query(int p,int k){
	if(t[p].l==t[p].r) return t[p].l;
	if(t[ls(p)].val>=k) return query(ls(p),k);
	return query(rs(p),k-t[ls(p)].val);
}

int main(){
	scanf("%d %d",&n,&k);
	int maxx=0;
	for(int i=1,t;i<=n;i++){
		scanf("%d",&t);
		tong[t]=1;
		maxx=max(maxx,t);
	}
	build(1,1,maxx);
	if(k>t[1].val) printf("NO RESULT\n");
	else printf("%d\n",query(1,k));
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

