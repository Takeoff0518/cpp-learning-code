#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
ll power(ll x,ll y,ll p){
	ll ans=1;
	while(y){
		if(y&1) ans=ans*x%p;
		x=x*x%p;
		y>>=1;
	}
	return ans%p;
}
int main(){
	ll a,b,p; 
	cin>>a>>b;
	ll ans=power(a,b,1e10+9);
	if(ans>1e9){
		puts("-1");
	}else{
		cout<<ans<<endl;
	}
    return 0;
}
//F**k CCF!!!!!

