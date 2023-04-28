#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll long long
const int N=1005,M=40005;
const int INF=0x3f3f3f3f;
const int p=1e9+7;
using namespace std;
ll f[N][M],g[N][M],cnt[N]; 
ll n,k;
int main(){
	cin>>n>>k;
	ll sq=sqrt(n);
	for(int i=1;i<sq;i++){
		cnt[i]=(n/i)-(n/(i+1));
	}
	cnt[sq]=(n/sq)-sq;
	for(int i=1;i<=sq;i++){
		f[1][i]=1,g[1][i]=cnt[i];
	}
	for(int i=1;i<=k;i++){
		ll ans=0;
		for(int j=1;j<=sq;j++){
			ans+=f[i][j];ans%=p;
			g[i+1][j]=ans*cnt[j];
		}
		for(int j=sq;j>=1;j--){
			ans+=g[i][j];ans%=p;
			f[i+1][j]=ans;
		}
	}
	cout<<f[k+1][1]<<endl;
    return 0;
}

