#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (105)
#define M (10005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
int a[N],f[N][M]; //f[i][j]为用前i道菜用光j元钱的办法总数
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            int &t=f[i][j];
            if(j==a[i]) t=f[i-1][j]+1;
            else if(j>a[i]) t=f[i-1][j-a[i]]+f[i-1][j];
            else t=f[i-1][j];
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}