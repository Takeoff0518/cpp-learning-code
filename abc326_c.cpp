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
int n,m,a[N],ans=0;
int pre[N];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		printf("%d ",a[i]);
//	}
//	puts("");
	int j=0;
	for(int i=1;i<=n;i++){
		while(j<=n && a[j]-a[i]<m){
			j++;
		}
//		printf("%d\n",j);
		ans=max(ans,j-i);
	}
	printf("%d\n",ans);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

