#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1000005,M=80005,p=2e5;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,a[N],f[N][M],ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		ans++;
		for(int j=i-1;j>=1;j--){
			f[i][a[i]-a[j]+p]+=f[j][a[i]-a[j]+p]+1;
			f[i][a[i]-a[j]+p]%=p;
			ans+=f[j][a[i]-a[j]+p]+1;
			ans%=p;
		}
	}
	cout<<ans<<endl;
    return 0;
}

