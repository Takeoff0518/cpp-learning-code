#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (100005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N];
int ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
	}
	printf("%d\n",ans+a[1]);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

