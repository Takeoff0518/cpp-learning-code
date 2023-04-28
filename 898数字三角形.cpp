#include<iostream>
#include<cstdio>
#define INF 0x3f3f3f3f
#define N 505
using namespace std;
int n;
int a[N][N],f[N][N];
/*
状态表示：
    集合：所有从起点走到(i,j)的路径
    属性：最大值
状态计算：f[i,j]
左上：f[i-1,j-1]+a[i,j]
右上：f[i-1,j]+a[i,j]
*/
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i+1;j++){
            f[i][j]=-INF;
        }
    }
    f[1][1]=a[1][1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            f[i][j]=max(f[i-1][j-1],f[i-1][j])+a[i][j];
        }
    }
    int ans=-INF;
    for(int i=1;i<=n;i++){
        ans=max(ans,f[n][i]);
    }
    printf("%d\n",ans);
    return 0;
}