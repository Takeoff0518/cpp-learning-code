#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (100005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,k;
ll a[N],pre[N];
int main(){
	freopen("mid.in","r",stdin);
	freopen("mid.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	scanf("%d",&k);
	while(k--){
		ll q;
		scanf("%lld",&q);
		int idx=lower_bound(a+1,a+n+1,q)-a;
//		printf("idx:%d\n",idx);
		printf("%lld\n",pre[n]-pre[idx-1]-q*(n-idx+1));
	}
	return 0;
}

