#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1000005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int q,n,m;
int a[N],b[N]; 
int main(){
	freopen("laundry.in","r",stdin);
	freopen("laundry.out","w",stdout);
	scanf("%d %d %d",&q,&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	printf("%d\n",a[1]+b[1]);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

