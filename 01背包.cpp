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
int n,m;
int v[N],w[N];
int f[N][N];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&v[i],&w[i]);
    //f[0][1~m]=0;
    //f[i][只用到f[i-1][];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            f[i][j]=f[i-1][j];
            if(j>=v[i])
                f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
        }
    }
    printf("  ");
    for(int i=0;i<=m;i++) printf("%d ",i);
    puts("");
    for(int i=1;i<=n;i++){
        printf("%d:",i);
        for(int j=0;j<=m;j++){
            printf("%d ",f[i][j]);
        }
        puts("");
    }
    printf("%d\n",f[n][m]);
    return 0;
}