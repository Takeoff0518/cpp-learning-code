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
int n,m,t;
int w[N][N],f[N][N];
/*
很重要的划分依据：根据最后一步划分
划分原则：
1. 不重复（求min,max）
2. 不漏
f[i,j]:
最后一步是从上边过来的 | 最后一步是从左边过来的
f[i-1,j]+w[i,j]      | f[i,j-1]+w[i,j]
两部分取max
*/
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>w[i][j];
                // f[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=max(f[i-1][j],f[i][j-1])+w[i][j];
            }
        }
        cout<<f[n][m]<<endl;
    }
    return 0;
}