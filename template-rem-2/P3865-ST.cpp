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
int n,m,f[N][18],a[N],lg[N];
int main(){
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	lg[0]=-1;
	for(int i=1;i<=n;i++){
		lg[i]=lg[i>>1]+1;
		f[i][0]=a[i];
	}
	for(int j=1;j<=18;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	while(m--){
		int l,r;
		scanf("%d %d",&l,&r);
		int s=lg[r-l+1];
		printf("%d\n",max(f[l][s],f[r-(1<<s)+1][s]));
	}
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

