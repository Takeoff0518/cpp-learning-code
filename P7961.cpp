#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,k;
ll v[N],a[N],ans;
inline ll popcnt(ll x){
	ll tmp=0;
	while(x){
		tmp+=x&1;
		x>>=1;
	}
	return tmp;
}
void dfs(int x){
	if(x==n+1){
		ll s=0;
		
		//debug
		cout<<"*";
		for(int i=1;i<=n;i++){
			cout<<a[i]<<' ';
		}
		cout<<endl;
		//*****
		for(int i=1;i<=n;i++){
			s+=(1<<a[i]);
//			cout<<"*"<<s<<endl;
		}
		if(popcnt(s)<=k){
			ll s=1;
			for(int i=1;i<=n;i++){
				s*=1LL*v[a[i]];
//				s%=mod;
			}
			ans=(ans+s)%mod;
		}
		return;
	}
	for(int i=0;i<=m;i++){
		a[x]=i;
		dfs(x+1);
	}
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d",&v[i]);
	}
	dfs(1);
	printf("%lld\n",ans);
    return 0;
}
//F**k CCF!!!!!

