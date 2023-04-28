#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
const int N=2005,M=180005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m,v,e;
int c[N],d[N];
double dp[N][N][2],f[N][N],k[N];//第i个阶段，连同这一次已经用了j次，当前这次换和不换的最小期望总和
int main(){
    memset(f,127,sizeof(f));
    memset(dp,127,sizeof(dp));
    scanf("%d %d %d %d",&n,&m,&v,&e);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);//安排的教室
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i]);//另一间上同样课的教室
    }
    for(int i=1;i<=n;i++){
        scanf("%lf",&n[i]);//更换教室申请通过的概率
    }
    for(int i=1;i<=e;i++){
        int a1,a2;
        double a3;
        scanf("%d %d %lf",&a1,&a2,&a3);
        f[a1][a2]=f[a2][a1]=min(f[a1][a2],a3);

    }
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
                f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    
    dp[1][0][0]=dp[1][1][1]=0.0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=min(m,i);j++){
            dp[i][j][0]=min(dp[i-1][j][0]+f[c[i-1]][c[i]],
                            dp[i-1][j][1]+f[d[i-1]][c[i]]*n[i-1]+f[c[i-1]][c[i]]*(1-n[i-1]));
            if(j!=0)
                dp[i][j][1]=min(dp[i-1][j-1][0]+f[c[i-1]][d[i]]*n[i]+f[c[i-1]][c[i]]*(1-n[i]),
                                dp[i-1][j-1][1]+f[c[i-1]][c[i]]*(1-n[i-1])*(1-n[i])+f[c[i-1]][d[i]]*(1-n[i-1])*n[i]+f[d[i-1]][c[i]]*(1-n[i])*n[i-1]+f[d[i-1]][d[i]]*n[i-1]*n[i]);
        }
    }
    double ans=1e9;
    for(int i=0;i<=m;i++){
        ans=min({dp[n][i][0],dp[n][i][1],ans});
    }
    printf("%.2lf",ans);
    return 0;
}