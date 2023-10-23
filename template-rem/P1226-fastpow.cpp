#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
ll ksm(ll x,ll y,ll p){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p;
		y>>=1;
	}
	return ans;
}
ll a,b,p;
int main(){
	scanf("%lld %lld %lld",&a,&b,&p);
	printf("%lld^%lld mod %lld=%lld\n",a,b,p,ksm(a,b,p));
    return 0;
}

