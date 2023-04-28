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
int n;
ll f[N];
bool p[N];
int main(){
    for(int i=2;i<=500;i++)
        if(!p[i])
            for(int j=2;i*j<=1000;j++)
                p[i*j]=1;
    f[0]=1; //如果n本身是一个素数，那么n＋0也是一个，根据我们的算法，合法的答案。
    cin>>n;
    for(int i=2;i<=n;i++){
        if(!p[i]){
            for(int j=i;j<=n;j++){
                f[j]+=f[j-i];
            }
        }
    }
    cout<<f[n]<<endl;
    return 0;
}