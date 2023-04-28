#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (35)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,u;
int a[N][N];
int main(){
	scanf("%d %d %d",&n,&m,&u);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	return 0;
}