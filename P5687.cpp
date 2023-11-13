#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (300005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
int a[N],b[N];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(a+1,a+n+1); sort(b+1,b+m+1);
	ll ans=a[1]*(m-1LL)+b[1]*(n-1LL);
	ll sum=n+m-2;
	int h=1,l=1,p1=2,p2=2;
	while(sum<1LL*n*m-1){
		if(a[p1]<b[p2]){
			ans+=1LL*a[p1++]*(m-h);
			l++;
			sum+=m-h;
		}else{
			ans+=1LL*b[p2++]*(n-l);
			h++;
			sum+=n-l;
		}
	}
	printf("%lld\n",ans);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

