#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (262144+10)
#define M (58+10)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N],ans;
int f[M][N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[a[i]][i]=i+1;
	}
	for(int i=2;i<=58;i++){
		for(int j=1;j<=n;j++){
			if(!f[i][j]) f[i][j]=f[i-1][f[i-1][j]];
			if(f[i][j]) ans=i;
		}
	}
	printf("%d",ans);
    return 0;
}
//F**k CCF!!!!!

