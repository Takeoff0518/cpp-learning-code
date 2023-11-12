#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector> 
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
vector<ll>we;
ll n,w;
ll p[N];
int cnt_e(ll x){
	int cnt=0;
	for(ll i=1;i*i<=x;i++){
		if(x%i==0){
			if(i*i!=x) cnt+=2;
			else cnt++;
		}
	}
	return cnt;
}
int main(){
	scanf("%lld %lld",&n,&w);
	for(int i=1;i<=n;i++){
		scanf("%lld",&p[i]);
	}
	for(ll i=1;i*i<=w;i++){
		if(w%i==0){
			we.push_back(i);
			if(i*i!=w) we.push_back(w/i);
		}
	}
	sort(we.begin(),we.end());
	for(ll t:we) printf("%lld ",t);
	puts("");
	for(int i=1;i<=n;i++){
		for(auto it=we.begin();it!=we.end();it++){
			if(p[i]%(*it)!=0){
				p[i]*=(*it);
				we.erase(it);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		ans=ans*cnt_e(p[i])%mod;
	}
	printf("%lld\n",ans);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

