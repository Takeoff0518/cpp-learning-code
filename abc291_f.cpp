#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (100005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
int f[2][N];
char t[N][15];
// int g[N][N];
int ans;
int main(){
    scanf("%d %d",&n,&m);
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        scanf("%s",t[i]+1);
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(t[i][j]==1){
    //             // add(i,i+j);
    //             // add(i+j,i);

    //         }
    //     }
    // }
    f[0][1]=f[1][n]=0;
    for(int i=1;i<=n;i++){
        for(int j=max(1,i-m);j<i;j++){
            if(t[j][i-j]=='1'){
                f[0][i]=min(f[0][j]+1,f[0][i]);
            }
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=min(i+m,n);j>i;j--){
            if(t[i][j-i]=='1'){
                f[1][i]=min(f[1][j]+1,f[1][i]);
            }
        }
    }
    for(int i=2;i<n;i++){
        ans=INF;
        for(int j=max(i-m,1);j<i;j++){
            for(int k=i+1;k<=min(i+m,n);k++){
                if(k-j<=m && t[j][k-j]=='1'){
                    ans=min(f[0][j]+f[1][k]+1,ans);
                }
            }
        }
        printf("%d ",ans==INF ? -1 : ans);
    }
    return 0;
}