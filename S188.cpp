#pragma GCC optimize(2)
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
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
ll solve(ll x){
	ll tmp=1;
	while(x){
		tmp*=x%10;
		x/=10;
		if(tmp==0) return 0ll;
	}
	return tmp;
}
ll ans=0;
int main(){
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		if(solve(i)<=k) ans++;
	}
	cout<<ans<<endl; 
    return 0;
}
//F**k CCF!!!!!

