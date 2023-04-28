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
struct node{
    int a,b;
    bool operator < (const node &x) const{
        return x.a==a ? x.b<b : x.a<a;
    }
}s[N];
inline ll power(ll x,ll y){
    ll ans=0;
    while(y){
        if(y&1){
            ans=ans*x%mod;
        }
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
ll tot,sum;
int bul_a[N],bul_b[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].b;
        bul_a[s[i].a]++;
        bul_b[s[i].b]++;
    }
    sort(s+1,s+n+1);
    tot=power(2,n)%mod;
    for(int i=1;i<=10000;i++){
        if(bul_a[i]>1){
            
        }
        if(bul_b[i]>1){

        }
    }
    return 0;
}