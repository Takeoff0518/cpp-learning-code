#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=10005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m,n,x[N],y[N];
int up[N],down[N];
int f[N][M];// f[i][j]到(i,j)最小的点击次数
// struct node{
//     int id,low,high;
//     #define id(xxx) tb[xxx].id
//     #define low(xxx) tb[xxx].low
//     #define high(xxx) tb[xxx].high
//     inline bool operator < (const node &x) const{
//         return x.id<id;
//     }
// }tb[M];
int ans,cnt;
int main(){
    scanf("%d %d %d",&n,&m,&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&x[i],&y[i]);
    }
    for(int i=1;i<=n;i++){
        down[i]=0,up[i]=m+1;
    }
    for(int i=1,p,l,h;i<=n;i++){
        scanf("%d %d %d",&p,&l,&h);
        down[p]=l,up[p]=h;
    }
    // sort(tb+1,tb+m+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            f[i][j]=INF;
        }
    }
    f[0][0]=INF;
    int arr=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j>=x[i-1]){
                f[i][j]=min({f[i][j],f[i-1][j-x[i-1]]+1,f[i][j-x[i-1]]+1});
            }
            if(j==m){
                for(int k=j-x[i-1];k<=m;k++){
                    f[i][j]=min({f[i][j],f[i-1][k]+1,f[i][k]+1});
                }
            }
        }
        for(int j=down[i]+1;j<=up[i]-1;j++){
            if(j+y[i-1]<=m){
                f[i][j]=min(f[i][j],f[i-1][j+y[i-1]]);
            }
        }
        for(int j=1;j<=down[i];j++){
            f[i][j]=INF;
        }
        for(int j=up[i];j<=m;j++){
            f[i][j]=INF;
        }
    }

    cnt=n,ans=INF;
    for(int i=n;i>=1;i--){
        for(int j=down[i]+1;j<=up[i]-1;j++){
            ans=min(ans,f[i][j]);
        }
        if(ans!=INF){
            break;
        }
        if(up[i]<=m){
            cnt--;
        }
    }
    if(cnt==n){
        printf("1 \n%d\n",ans);
    }else{
        printf("0 \n%d\n",cnt);
    }
    return 0;
}