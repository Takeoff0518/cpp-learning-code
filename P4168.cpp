#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,a[N],x;
int ans[N][N],maxx[N][N];
int cnt[N][N];
int st[N],ed[N],bel[N],siz[N];
void init(){
	int sq=sqrt(n)+1;
	for(int i=1;i<=sq;i++){
		st[i]=n/sq*(i-1)+1;
		ed[i]=n/sq*i;
	}
	ed[sq]=n;
	for(int i=1;i<=sq;i++){
		for(int j=st[i];j<=ed[i];j++){
			bel[j]=i;
		}
	}
	
	for(int i=1;i<=sq;i++){
		siz[i]=ed[i]-st[i]+1;
	}
	for(int i=1;i<=n;i++){
		cnt[bel[i]][a[i]]++;
	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		l=(l+x-1)%mod,r=(r+x-1)%mod;
		if(l>r) swap(l,r);
		
	}
	return 0;
}

