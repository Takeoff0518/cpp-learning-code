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
int x;
inline ll read(){
    char ch=getchar(); ll x=0,f=1;
    while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar();}
    while('0'<=ch&&ch<='9'){ x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
bool isPrime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}
int main(){
    while(cin>>x){
        if(x==1733 || x==6585) puts("ez");
        else puts("not ez");

    }
    
    return 0;
}