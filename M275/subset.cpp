#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll unsigned long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
void bf(); 
ll n,m;
//ll f[N][N];
/*
----> j,m
|
|
|
i,n
*/
ll ksm(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
int main(){
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	scanf("%lld %lld",&n,&m);
//	bf();
	printf("%lld\n",ksm((m+1)%mod,n));
    return 0;
}

void bf(){
	if(n==1){
		printf("%lld\n",m+1);
		exit(0);
	}
	if(m==1){
		printf("%lld\n",ksm(2,n));
		exit(0);
	}
}

