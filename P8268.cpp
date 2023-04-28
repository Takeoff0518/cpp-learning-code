#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (105)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N];
int k;
int m[N],g[N][N];
int ans=0;
bool dfs(int x){
    if(a[x]>0) return 1;
    if(m[x]==0) return 0;
    for(int i=m[x];i>=1;i--)
        if(!dfs(g[x][i])) return 0;
    for(int i=1;i<=m[x];i++)
        a[g[x][i]]--;
    a[x]++;
    return 1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    ans=a[n],a[n]=0;
    scanf("%d",&k);
    for(int i=1,x;i<=k;i++){
        scanf("%d",&x);
        scanf("%d",&m[x]);
        for(int j=1;j<=m[x];j++){
            scanf("%d",&g[x][j]);
        }
    }
    while(dfs(n)) ans++,a[n]--;
    printf("%d\n",ans);
    return 0;
}