#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 1005
using namespace std;
/*
状态表示f[i,j]：
    集合：第一个序列的前i个字母中出现，且在第二个序列的前j个字母中出现的子序列
    属性：最大值
状态计算：
*/
char a[N],b[N];
int f[N][N];
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    cin>>a+1>>b+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j]){
                f[i][j]=max(f[i][j],f[i-1][j-1]+1);
            }
        }
    }
    printf("%d",f[n][m]);
    return 0;
}