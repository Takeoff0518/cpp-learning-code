#include<iostream>
using namespace std;
int a[1005][1005],dp[1005][1005];
int main(){
	int r;
	cin>>r;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=i;j++)
			cin>>a[i][j];
	for(int i=1;i<=r;i++)
		for(int j=1;j<=i;j++)
			dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
	int maxx=0x3f3f3f3f;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=i;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i=1;i<=r;i++)
		maxx=min(dp[r][i],maxx);
	cout<<maxx;
}
