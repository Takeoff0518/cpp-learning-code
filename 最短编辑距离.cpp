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
int f[N][N];
/*
增：f[i-1][j]+1
删：f[i][j-1]+1
改：f[i-1][j-1]+1/0（相等）
f[i][j]=min(...,...,...)
*/
int n,m;
char a[N],b[N];
int main(){
    cin>>n>>a+1>>m>>b+1;//0-1=-1，会越界，从1开始比较好
    for(int i=1;i<=max(n,m);i++) f[0][i]=f[i][0]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=min(f[i-1][j],f[i][j-1])+1;
            if(a[i]==b[j]) f[i][j]=min(f[i][j],f[i-1][j-1]);
            else f[i][j]=min(f[i][j],f[i-1][j-1]+1);
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}