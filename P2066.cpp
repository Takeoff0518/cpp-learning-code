#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (20)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
int a[N][N],f[N][N],ans[N][N][N];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=j;k++){
                if(f[i][j]<f[i-1][k]+a[i][j-k]){
                    f[i][j]=f[i-1][k]+a[i][j-k];
                    for(int l=1;l<i;l++)
                        ans[i][j][l]=ans[i-1][j][l];
                    ans[i][j][i]=j-k;
                }
            }
    printf("%d\n",f[n][m]);
    for(int i=1;i<=n;i++)
        printf("%d %d\n",i,ans[n][m][i]);
    return 0;
}