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
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b) x=1,y=0;
	else{
		exgcd(b,a%b,y,x);
		y-=a/b*x;
	}
}
ll power(ll x,ll y,ll p){
	ll ans=1;
	while(y){
		if(y&1){
			
		}
	}
}
int main(){
	
	return 0;
}