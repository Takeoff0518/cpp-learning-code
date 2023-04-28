#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (105)
#define M (11)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
int a[N],sum[N],f[N][N][M],d[N][N][M];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    // int n2=n<<1;
    memset(d,INF,sizeof(d));
    for(int i=1;i<=n*2;i++) a[i]+=a[i-1];
    for(int i=1;i<=n*2;i++)
        for(int j=i;j<=n*2;j++)
            f[i][j][1]=d[i][j][1]=(a[j]-a[i-1]+100000)%10;
    for(int i=2;i<=m;i++){
        for(int l=1;l<=n*2;l++){
            for(int r=i+l-1;r<=n*2;r++){
                for(int k=i+l-2;k<r;k++){
                    d[l][r][i]=min(d[l][r][i],d[l][k][i-1]*((a[r]-a[k]+100000)%10));
                    f[l][r][i]=max(f[l][r][i],f[l][k][i-1]*((a[r]-a[k]+100000)%10));
                }
            }
        }
    }
    int maxx=0,minn=INF;
    for(int i=1;i<=n;i++){
        maxx=max(maxx,f[i][i+n-1][m]);
        minn=min(minn,d[i][i+n-1][m]);
    }
    printf("%d\n%d",minn,maxx);
    return 0;
}