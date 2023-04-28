#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 1005
#define M 10005
#define mod 19650827
using namespace std;
int f[N][N][2],a[N];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        f[i][i][0]=1;
    }
    for(int i=n;i>=0;i--){
        for(int j=i+1;j<=n;j++){
            f[i][j][0]=f[i+1][j][0]*(a[i]<a[i+1])+f[i+1][j][1]*(a[i]<a[j]);
			f[i][j][1]=f[i][j-1][0]*(a[j]>a[i])+f[i][j-1][1]*(a[j]>a[j-1]);
			f[i][j][0]%=mod,f[i][j][1]%=mod;
        }
    }
    printf("%d\n",(f[1][n][0]+f[1][n][1])%mod);
    return 0;
}