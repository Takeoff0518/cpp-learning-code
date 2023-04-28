#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=35,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,a[N],dp[N][N],root[N][N];
int dfs(int l,int r){
	if(l>r) return 1;
	if(dp[l][r]) return dp[l][r];
	for(int i=l;i<=r;i++){
		int t=dfs(l,i-1)*dfs(i+1,r)+a[i];
		if(dp[l][r]<t){
			dp[l][r]=t;
			root[l][r]=i;
		}
	}
	return dp[l][r];
}
void print(int l,int r){
	if(l>r) return;
	printf("%d ",root[l][r]);
	print(l,root[l][r]-1);
	print(root[l][r]+1,r);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i][i]=a[i];
		root[i][i]=i; 
	}
	int ans=dfs(1,n);
	printf("%d\n",dfs(1,n));
	print(1,n);
    return 0;
}
//F**k CCF!!!!!

