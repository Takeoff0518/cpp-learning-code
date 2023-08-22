#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
ll n,k;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%lld %lld",&n,&k);
	ll ans=n*k;
	for(ll l=1,r;l<=n;l=r+1){
		r=k/l==0 ? n : min(k/(k/l),n);
		ans-=(k/l)*(r-l+1)*(l+r)/2;
	}
	printf("%lld\n",ans);
	return 0;
}
