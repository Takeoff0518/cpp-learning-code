#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (200005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N],ans=INF;
void dfs(int x,int maxx,int minn){
	if(x==n+1){
		ans=min(ans,maxx-minn);
		return;
	}
	// 1:
	dfs(x+1,max(maxx,a[x]),min(minn,a[x]));
	// 2:
	if(x+1!=n+1){
		dfs(x+2,max(maxx,a[x]+a[x+1]),min(minn,a[x]+a[x+1]));
	}
}
int main(){
	freopen("segment.in","r",stdin);
	freopen("segment.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,-INF,INF);
	printf("%d\n",ans);
	return 0;
}

