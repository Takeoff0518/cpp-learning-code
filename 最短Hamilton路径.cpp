#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (20)
#define M (1<<N)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int w[N][N],f[M][N];
int n;
// f[i][j]:所有从0走到j，走过的所有点是i的所有路径
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&w[i][j]);
        }
    }
    memset(f,0x3f,sizeof(f));
    f[1][0]=0; //起点在0位置（0->0）
    for(int i=0;i<(1<<n);i++){//枚举所有位置
        for(int j=0;j<n;j++){
            if(i>>j&1){//0->j，i中一定包含{j}
                for(int k=0;k<n;k++){//枚举从哪个点转移
                    //i中除去{j}这个点后，一定包含k才能走到k 0->k->j
                    if((i-(1<<j))>>k&1){
                        f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j]);
                    }
                }
            }
        }
    }
    printf("%d\n",f[(1<<n)-1][n-1]);
    return 0;
}