#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (15)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
/*
f[i1,j1,i2,j2]表示所有从(1,1),(1,1)
分别走到(i1,j1),(i2,j2)的路径的最大值
如何处理“同一个格子不能被重复选择”：
只有在i1+j1==i2+j2时，两条路径的格子才可能重合
优化：f[k,i1,i2] 分别走到(i1,k-i1),(i2,k-i2)的路径的最大值
k为两条路线当前走到格子的横纵坐标之和 k=i1+j1=i2+j2
f[k,i1,i2]:
第一条：下|下|右|右
第二条：下|右|下|右
重合：+w[i1][j1]
不重合：+w[i1][j1]+w[i2][j2]
*/
int n,w[N][N],f[N+N][N][N];
int main(){
    cin>>n;
    int a,b,c;
    while(cin>>a>>b>>c,a||b||c) w[a][b]=c;
    for(int k=2;k<=n+n;k++)
        for(int i1=1;i1<=n;i1++)
            for(int i2=1;i2<=n;i2++){
                int j1=k-i1,j2=k-i2;
                if(j1>=1 && j1<=n && j2>=1 && j2<=n){
                    int t=w[i1][j1],&x=f[k][i1][i2];
                    if(i1!=i2) t+=w[i2][j2]; //重合，只加一次
                    x=max(x,f[k-1][i1-1][i2-1]+t);
                    x=max(x,f[k-1][i1-1][i2]+t);
                    x=max(x,f[k-1][i1][i2-1]+t);
                    x=max(x,f[k-1][i1][i2]+t);
                }
            }
    cout<<f[n+n][n][n];
    return 0;
}