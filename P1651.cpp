#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (55)
#define M (500005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N],f[N][M],tot;
//f[i][j]表示遍历到第i块水晶时，使两塔高度差为j时，较高的塔的高度
int main(){
    scanf("%d",&n);
    memset(f,-0x3f,sizeof(f));
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        tot+=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=tot;j>=0;j--){
            //不要第i个水晶就能达成j的差
            f[i][j]=max(f[i][j],f[i-1][j]);
            //把第i个水晶放在矮塔上，矮塔依然是矮塔
            f[i][j]=max(f[i][j],f[i-1][j+a[i]]);
            //把第i个水晶放在高塔上达成j的差
            if(j>=a[i]) f[i][j]=max(f[i][j],f[i-1][j-a[i]]+a[i]);
            //把第i个水晶放在矮塔上，但矮塔成为高塔
            if(j<=a[i]) f[i][j]=max(f[i][j],f[i-1][a[i]-j]+j);
        }
    }
    if(f[n][0]==0) printf("-1\n");
    else printf("%d\n",f[n][0]);
    return 0;
}