/*
01背包：每件物品最多只用一次
完全背包：每件物品有无限个
多重背包：每件物品有个数限制
*/
#include<iostream>
#include<cstdio>
#define N 1005
using namespace std;
int n,m;
int v[N],w[N];
int c[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    //f[0][0~m]=0;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){//直接删掉，等价于f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);，所以要反着跑
            // f[j]=f[j];
            c[j]=max(c[j],c[j-v[i]]+w[i]);
        }
    }
    cout<<c[m];
    return 0;
}