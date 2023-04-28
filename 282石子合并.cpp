#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 305
using namespace std;
/*
状态表示f[i][j]：
    集合：所有将第i堆石子到第j堆石子合并成一堆石子的合并方式
    属性：最小值
状态计算：f[i][k]=max(f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
*/
int n,sum[N],f[N][N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&sum[i]);
    }
    for(int i=1;i<=n;i++){
        sum[i]+=sum[i-1];
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int l=i,r=i+len-1;
            f[l][r]=INF;
            for(int k=l;k<r;k++){
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+sum[r]-sum[l-1]);
            }
        }
    }
    printf("%d\n",f[1][n]);
    return 0;
}