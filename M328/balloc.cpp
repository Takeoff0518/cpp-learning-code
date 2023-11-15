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
int c[N],a[N],b[N];
int cov[N];
bool num[N];
bool check(){
	memset(cov,0,sizeof(cov));
	for(int i=1;i<=m;i++){
		if(num[i]){
			for(int j=a[i];j<=b[i];j++) cov[j]++; 
		}
	}
	for(int i=1;i<=n;i++) if(cov[i]>c[i]) return 0;
	return 1;
}
int ans=0;
void dfs(int x,int cnt){
	if(x==m+1){
		if(check()) ans=max(ans,cnt);
		return;
	}
	num[x]=1;
	dfs(x+1,cnt+1);
	num[x]=0;
	dfs(x+1,cnt);
}
int main(){
	freopen("balloc.in","r",stdin);
	freopen("balloc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	dfs(1,0);
	printf("%d\n",ans);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

