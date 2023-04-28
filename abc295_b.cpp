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
int n,m;
char g[N][N];
inline int abs(int x){
    return x>0 ? x : -x;
}
void boom(int x,int y,int k){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((abs(x-i)+abs(y-j)<=k) && g[i][j]=='#'){
                g[i][j]='.';
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]>='0' && g[i][j]<='9'){
                boom(i,j,g[i][j]-'0');
                g[i][j]='.';
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<g[i][j];
        }
        cout<<endl;
    }
    return 0;
}