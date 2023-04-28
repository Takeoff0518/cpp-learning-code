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
int t,n,a[N],pre[N],l[N][N],r[N][N];
// inline int sum(int x,int y){
//     if(x>y) swap(x,y);
//     return pre[y]-pre[x-1];
// }
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            pre[i]=pre[i-1]+a[i];
            l[i][i]=r[i][i]=a[i];
        }
        for(int len=1;len<n;len++){
            for(int i=1;i+len<=n;i++){
                int j=i+len;
                l[i][j]=a[i]+max(l[i+1][j],pre[j]-pre[i]-max(l[i+1][j],r[i+1][j]));
                r[i][j]=a[j]+max(r[i][j-1],pre[j-1]-pre[i-1]-max(l[i][j-1],r[i][j-1]));
            }
        }
        printf("%d\n",max(l[1][n],r[1][n]));
    }
    return 0;
}