#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=100005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
void exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0) x=1,y=0;
	else{
		exgcd(b,a%b,x,y);
		int t=x;
		x=y;
		y=t-(a/b)*y;
	}
}
ll a[N],m[N],Mi[N],ans,n,mul=1;
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		ll M;
		scanf("%lld",&M);
		m[i]=M;
		mul*=M;
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		Mi[i]=mul/m[i];
		ll x=0,y=0;
		exgcd(Mi[i],m[i],x,y);
		ans+=a[i]*Mi[i]*(x<0 ? x+m[i] : x);
	}
	printf("%lld",ans%mul);
    return 0;
}
//F**k CCF!!!!!

