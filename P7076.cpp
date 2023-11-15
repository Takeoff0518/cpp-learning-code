#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define ull unsigned ll
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,c; ull k;
ull need,lim;
int main(){
	scanf("%d %d %d %llu",&n,&m,&c,&k);
	for(int i=1;i<=n;i++){
		ull a; scanf("%llu",&a);
		need|=a;
	}
	for(int i=1;i<=m;i++){
		int p; scanf("%d",&p);
		lim|=1ull<<p;
		scanf("%llu");
	}
	int ans=0;
	for(int i=0;i<k;i++){
		ans+=!((lim>>i)&1)||((need)>>i)&1;
	}
	if(ans==64&&!n) printf("18446744073709551616");
	else printf("%llu",ans==64 ? -n : ((1ull<<ans)-n));
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

