#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (50005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n;
char g[N][7];
int check(int x){

}
int main(){
    cin>>n;
    for(int i=1;i<=n*4-1;i++){
        for(int j=1;j<=5;j++){
            cin>>g[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        cout<<check(i);
    }
    return 0;
}