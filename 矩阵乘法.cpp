#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=505,M=1005;
const int INF=0x3f3f3f3f;
const int p=1e9+7;
using namespace std;
struct matrix{
    int n,m;
    int z[N][N];//z[i][j]
    matrix(){
        n=m=0;
        memset(z,0,sizeof(z));
    }
};
matrix t;
matrix operator * (const matrix &m1,const matrix &m2){
    // matrix m3;//局部变量
    t.n=m1.n;
    t.m=m2.m;
    for(int i=1;i<=t.n;i++){
        for(int k=1;k<=m1.m;k++){
            for(int j=1;j<=t.m;j++){
                t.z[i][j]+=m1.z[i][k]*m2.z[k][j];
            }
        }
    }
    return t;
}
matrix m1,m2,m3;
int main(){
    
    return 0;
}