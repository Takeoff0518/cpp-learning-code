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
int n,f[N];
int main(){
    cin>>n;
    f[0]=1;//f[1~...]=0
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            f[j]=(f[j]+f[i-j])%mod;
        }
    }
    cout<<f[n];
    return 0;
}