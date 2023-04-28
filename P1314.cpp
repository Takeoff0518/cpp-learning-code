#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll long long
const int N=200005,M=1005;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int p=998244353;
using namespace std;
ll n,m;
ll Y,W,sum,s;
ll w[N],v[N],l[N],r[N],pre_v[N],pre_n[N];
bool check(int W){
	Y=0,sum=0;
	memset(pre_n,0,sizeof(pre_n));
	memset(pre_v,0,sizeof(pre_v));
	for(int i=1;i<=n;i++){
		if(w[i]>=W){
			pre_n[i]=pre_n[i-1]+1;
			pre_v[i]=pre_v[i-1]+v[i];
		}else{
			pre_n[i]=pre_n[i-1];
			pre_v[i]=pre_v[i-1];
		}
	}
	for(int i=1;i<=m;i++){
		Y+=(pre_n[r[i]]-pre_n[l[i]-1])*(pre_v[r[i]]-pre_v[l[i]-1]);
	}
	sum=llabs(Y-s);
	if(Y>s){
		return 1;
	}
	else return 0;
}
ll mx=-INF,mn=INF;
int main(){
	scanf("%lld %lld %lld",&n,&m,&s);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&w[i],&v[i]);
		mx=max(mx,w[i]);
		mn=min(mn,w[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&l[i],&r[i]); 
	}
	int left=mn-1,right=mx+2,mid;
	ll ans=INF;
	while(left<=right){
		mid=(left+right)/2;
		if(check(mid)){
			left=mid+1;
		}else{
			right=mid-1;
		}
		ans=min(sum,ans);
	}
	cout<<ans<<endl;
    return 0;
}

