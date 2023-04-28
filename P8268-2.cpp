#include<iostream>
using namespace std;
int m[105],g[105][105],a[105],n,k,ans;
//sum[i]表示编号为i的金属需要几个金属来合成，num[i][j]表示合成金属i所需的第j个金属是谁。 
bool dfs(int x) {
	if(a[x]>0) return true;//第六行	
	if(m[x]==0) return false; 
	for(int i=m[x];i>=1;i--)//第八行 
		if(!dfs(g[x][i])) return false; 
	for(int i=1;i<=m[x];i++)
		a[g[x][i]]--; 
	a[x]++; 
	return true;
}
int main() {
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ans=a[n],a[n]=0;//a[n]一定要等于0，不然while会陷入死循环。 
	cin>>k;
	for(int i=1;i<=k;i++) {
		int x;
		cin>>x;
		cin>>m[x];
		for(int j=1;j<=m[x];j++)
			cin>>g[x][j];
	}
	while(dfs(n))
		ans++,a[n]--;//一定要a[n]--，不然第六行就一直返回true，while陷入死循环。 
	cout<<ans;
	return 0;
}
