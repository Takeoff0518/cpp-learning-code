#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (2005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N],f[N][N];
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(f,INF,sizeof(f));
        f[1][1]=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(f[i][j]!=INF){
                    if(a[i]<a[i+1]) f[i+1][j+1]=min(f[i+1][j+1],f[i][j]);
                    if(f[i][j]<a[i+1]) f[i+1][i-j+1]=min(f[i+1][i-j+1],a[i]);
                }
            }
        }
        if(f[n][n>>1]==INF) puts("No!");
        else puts("Yes!");
    }
    return 0;
}