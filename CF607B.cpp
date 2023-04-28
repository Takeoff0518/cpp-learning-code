#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=505,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int f[N][N];
int n,a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        f[i][i]=1;
    }
    for(int i=1;i<n;i++){
        f[i][i+1]= a[i]==a[i+1] ? 1 : 2;
    }
    for(int len=3;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            if(a[i]==a[j]){
                f[i][j]=f[i+1][j-1];
            }
            for(int k=i;k<j;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
            }
        }
    }
    printf("%d\n",f[1][n]);
    return 0;
}