#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=105,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
#define left 0
#define right 1
using namespace std;
int a[N],b[N],f[N][N][2],m[N],n,c;
int main(){
    scanf("%d %d",&n,&c);
    memset(f,0x3f,sizeof(f));
    for(int i=1,x,y;i<=n;i++){
        scanf("%d %d",&a[i],&b[i]);
        m[i]=m[i-1]+b[i];
    }
    f[c][c][left]=f[c][c][right]=0;
    // cout<<endl;
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            f[i][j][left]=min(f[i+1][j][left]+(a[i+1]-a[i])*(m[i]+m[n]-m[j]),\
                              f[i+1][j][right]+(a[j]-a[i])*(m[i]+m[n]-m[j]));// 折返
            f[i][j][right]=min(f[i][j-1][right]+(a[j]-a[j-1])*(m[i-1]+m[n]-m[j-1]),\
                               f[i][j-1][left]+(a[j]-a[i])*(m[i-1]+m[n]-m[j-1]));
        }
    }
    printf("%d\n",min(f[1][n][left],f[1][n][right]));
    return 0;
}