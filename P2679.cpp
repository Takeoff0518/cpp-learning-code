#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (205)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (1000000007)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,k;
char a[N],b[N];
ll f[2][M][M][2];
int main(){
	scanf("%d %d %d",&n,&m,&k);
	scanf("%s",a+1);
	scanf("%s",b+1);
//	memset(f,1,sizeof(f));
	f[0][0][0][0]=f[1][0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int p=1;p<=k;p++){
				if(a[i]==b[j]){
					f[i%2][j][p][0]=f[(i-1)%2][j][p][0]
								+f[(i-1)%2][j][p][1]; 
					f[i%2][j][p][1]=f[(i-1)%2][j-1][p][1]
								+f[(i-1)%2][j-1][p-1][0]
								+f[(i-1)%2][j-1][p-1][1];
				}else{
					f[i%2][j][p][0]=f[(i-1)%2][j][p][0]
								+f[(i-1)%2][j][p][1];
					f[i%2][j][p][1]=0;
				}
				f[i%2][j][p][0]%=mod;
				f[i%2][j][p][1]%=mod;
			}
		}
	}
	printf("%lld\n",(f[n%2][m][k][0]+f[n%2][m][k][1])%mod);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

