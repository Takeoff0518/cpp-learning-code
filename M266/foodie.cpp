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
int n,m,x;
int w[N],a[N];
int main(){
	freopen("foodie.in","r",stdin);
	freopen("foodie.out","w",stdout);
	scanf("%d %d %d",&n,&m,&x);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("%d\n",n+m);
    return 0;
}

