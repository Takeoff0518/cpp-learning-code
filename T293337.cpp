#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (5005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define p (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
ll a[N],n,sum;
bool all_1=1;
ll qpow(ll a,ll b){
	if(b==1)
		return a;
	ll t=qpow(a,b/2);
	t=t*t%p;
	if(b&1)
		t=t*a%p;
	return t;
}
ll cm(ll n,ll m){
	if(n<m)
		return 0;
	if(m>n-m)
		m=n-m;
	ll a=1,b=1;
	for(int i=0;i<m;i++){
		a=a*(n-i)%p;
		b=b*(i+1)%p;
	}
	return a*qpow(b,p-2)%p;
}
ll lucas(ll n,ll m){
	if(m==0)
		return 1;
	return lucas(n/p,m/p)*cm(n%p,m%p)%p;
}
int main(){
	scanf("%d",&n);
	for(int i=1,b;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
		if(a[i]!=1) all_1=0;
	}
	sort(a+1,a+n+1);
	if(n==1){
		puts("0");
		return 0;
	}
	if(n==2){
		if(a[1]==a[2]){
			puts("1");
		}else{
			puts("0");
		}
		return 0;
	}
	if(sum&1){
		puts("0");
		return 0;
	}
	
    return 0;
}
//F**k CCF!!!!!

