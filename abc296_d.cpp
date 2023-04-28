#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define N (1000000000005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
ll n,m,x,ans=INF;
int main(){
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        x=(m+i-1)/i;
        if(x<=n) ans=min(ans,i*x);
        if(i>x) break;
    }
    if(ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
/*
编写C++程序：从1,2,...n中随便找两个数a,b（a,b可以相等），使得a*b>=m，求出最小的a*b（例子：n=5,m=7,则a*b=8,即a=2,b=4）
*/