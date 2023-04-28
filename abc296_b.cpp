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
char g[N][N];
int x,y;
int main(){
    for(int i=8;i>=1;i--){
        for(int j=1;j<=8;j++){
            cin>>g[i][j];
            if(g[i][j]=='*') x=i,y=j;
        }
    }
    cout<<(char)(y+'a'-1)<<x;
    return 0;
}