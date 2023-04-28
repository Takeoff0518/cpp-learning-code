#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (2005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
ll n,m,ans=INF;
ll a[N][N];
ll f[N][N];
int main(){
	scanf("%lld",&n);
	m=n*(n+1)/2;
	int cnt=m;
	//cout<<cnt<<endl;
	for(int i=1;i<=n;i++){
		//if(!cnt) break;
		if(i&1){
			for(int j=1;j<=i;j++){
				a[i][j]=cnt--;
			}
		}else{
			for(int j=i;j>=1;j--){
				a[i][j]=cnt--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			f[i][j]=max(f[i-1][j-1],f[i-1][j])+a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		ans=min(ans,f[n][i]);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			printf("%d ",a[i][j]);
		}
		puts("");
	}
    return 0;
}
//F**k CCF!!!!!

