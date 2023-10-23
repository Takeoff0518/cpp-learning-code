#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#define N (1000005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n;
ll t1,t2;
vector<int> a;
int main(){
	freopen("netherwart.in","r",stdin);
	freopen("netherwart.out","w",stdout);
	scanf("%d %lld %lld",&n,&t1,&t2);
	for(int i=1,t;i<=n;i++){
		scanf("%d",&t);
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	for(ll i=1;i<=t1+t2;i++){
		for(int j=1;j<n;j++){
			a.push_back(a[j]+a[j-1]);
//			printf("add:%d\n",a[j]+a[j-1]);
		}
		n+=n-1;
		if(i==t1) sort(a.begin(),a.end());
	}
	ll ans=0;
	for(auto i:a){
//		printf("%d ",i);
		ans+=i;
		ans%=mod;
	}
//	puts("");
	printf("%d\n",ans);
    return 0;
}

