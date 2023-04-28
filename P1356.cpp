#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (10005)
#define M (105)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int t,n,k,a[N];
bool f[N][M];
inline int p(int x){
    return (x%k+k)%k;
}
int main(){+

    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(f,0,sizeof(f));
        
        f[1][p(a[1])]=f[1][p(-a[1])]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<k;j++){
                f[i][j]=f[i-1][p(j+a[i])] || f[i-1][p(j-a[i])];
            }
        }
        if(f[n][0]) puts("Divisible");
        else puts("Not divisible");
    }
    return 0;
}