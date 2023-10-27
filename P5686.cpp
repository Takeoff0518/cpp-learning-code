#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (500005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (1000000007)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n;
ll a[N],b[N];
ll pa[N],pb[N];
int main(){
	scanf("%d",&n);
	ll sum_pa=0,sum_pb=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		pa[i]=(pa[i-1]+a[i])%mod;
		sum_pa=(sum_pa+pa[i])%mod;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
		pb[i]=(pb[i-1]+b[i])%mod;
		sum_pb=(sum_pb+pb[i])%mod;
	}
	ll cnt=(sum_pa*sum_pb)%mod;
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+pa[i]*pb[i])%mod;
	}
	ans=(n+1)*ans%mod;
	ans=(ans-cnt+mod)%mod; 
	printf("%lld\n",ans);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

