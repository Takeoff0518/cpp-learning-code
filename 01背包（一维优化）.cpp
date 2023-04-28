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
int n,m;
int v[N],w[N];
int f[N];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&v[i],&w[i]);
    //f[0][1~m]=0;
    //f[i][只用到f[i-1][];
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
            // f[i][j]=f[i-1][j];
            // if(j>=v[i]
            /*
                直接删掉：f[i][j],f[i][j-v[i]];
                解决方式：倒序
                算f[j]时，由于j-v[i]<j，实际并未更新过，那么就是第i-1层的值
            */
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    printf("%d\n",f[m]);
    return 0;
}