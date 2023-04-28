#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
char a[N],b[N];
int f[N][N];
/*
不选ai,bj:f[i-1][j-1] 00 一般都不写，已经在11 01 10里面包含
同时包含ai,bj:f[i-1][j-1]+1 11
不选ai,选bj:f[i-1][j] 一定包含01，但不完全等价，不一定以bj结尾，包含bj
选ai,不选bj:f[i][j-1] 10
求最大值时可以有重复，但是不影响
若求数量时，不能有重复
*/
int n,m;
int main(){
	cin>>n>>m;
    cin>>a+1;
    cin>>b+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=max(f[i-1][j],f[i][j-1]);
			if(a[i]==b[j]) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
        }
    }
	cout<<f[n][m]<<endl;
    return 0;
}