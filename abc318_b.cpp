#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n;
int a[N],b[N],c[N],d[N];
bool g[N][N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
    }
    for(int idx=1;idx<=n;idx++){
        for(int i=a[idx]+1;i<=b[idx];i++){
            for(int j=c[idx]+1;j<=d[idx];j++){
                g[i][j]=true;
                // printf("%d,%d\n",i,j);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=102;i++){
        for(int j=1;j<=102;j++){
            ans+=g[i][j];
            // printf("%d",g[i][j]);
        }
        // puts("");
    }
    printf("%d\n",ans);
    return 0;
}