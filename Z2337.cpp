#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1000005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n;
ll a[N],pre[N],ans=0;
//inline bool cmp(int x,int y){
//	return x>y;
//}
bool check(ll x){
	for(int i=x;i<=n;i++){
		if(pre[i]<1ll*i*a[i-x+1]) return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		//printf("%d ",pre[i]);
	}
	//puts("");
	ll l=1,r=n,mid;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid))
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",ans);
    return 0;
}
//F**k CCF!!!!!

