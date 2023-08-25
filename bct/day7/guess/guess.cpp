#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (500005)
#define M (1000005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
//int f[M];
int n;
int main(){
	freopen("guess.in","r",stdin);
	freopen("guess.out","w",stdout);
//	memset(f,-1,sizeof(f));
	scanf("%d",&n);
	ll x;
//	f[1]=0;
	while(n--){
		scanf("%lld",&x);
		ll ans=0;
		while(x!=1){
			if(x&1) x=x*3+1,++ans;
			else x>>=1,++ans;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

