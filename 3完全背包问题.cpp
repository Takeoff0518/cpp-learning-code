#include<iostream>
#include<cstdio>
#define N 1005
using namespace std;
int n,m;
int v[N],w[N];
int f[N][N];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&v[i],&w[i]);
    }
   /*
   f[i,j]=Max(f[i-1,j],f[i-1,j-v]+w,f[i-1,j-2v]+2w,f[i-1,j-3v]+3w,.....);
   f[i,j-v]=Max(       f[i-1,j-v],  f[i-1,j-2v]+w, f[i-1,j-3v]+2w,....);
   f[i,j]=Max(f[i-1,j],f[i,j-v]+w)
   */
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            f[i][j]=f[i-1][j];
            if(j>=v[i]){
                f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
            }
        }
    }
    printf("%d\n",f[n][m]);
    return 0;
}