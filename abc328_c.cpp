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
char s[N];
int a[N],p[N];
int n,q;
int main(){
	scanf("%d %d",&n,&q);
	scanf("%s",s+1);
	for(int i=1;i<n;i++){
		if(s[i]==s[i+1]) a[i]=1;
	}
	for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		int ans=p[r-1]-p[l-1];
//		if(a[r]) ans--;
		printf("%d\n",ans);
	}
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

