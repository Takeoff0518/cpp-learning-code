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
int n,w[N][N],f[N][N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>w[i][j];
            
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1 && j==1) f[i][j]=w[i][j];
            else{
                f[i][j]=INF;
                if(i>1) f[i][j]=min(f[i][j],f[i-1][j]+w[i][j]); //只有不在第一行的时候,才可以从上面过来
                if(j>1) f[i][j]=min(f[i][j],f[i][j-1]+w[i][j]); //只有不在第一列的时候,才可以从左边过来
            } 
        }
    }
    cout<<f[n][n]<<endl;
    return 0;
}