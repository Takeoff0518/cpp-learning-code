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
int n,a[N],f[N];
int ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        f[i]=1;
        // g[i]=0;
        for(int j=1;j<=i;j++){
            if(a[j]<a[i])
                f[i]=max(f[i],f[j]+1);
        }
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}