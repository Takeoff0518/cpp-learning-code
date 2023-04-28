#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (100005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,p=1;
struct node{
    ll n,s,w;
}a[N];
ll ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i].s);
    for(int i=1;i<=n;i++) a[i].n=i+1;
    a[n].n=1;
    for(int i=1;i<=(n<<1);i++){
        if(a[p].s>1){
            a[a[p].n].s+=a[p].s-1;
            a[a[p].n].w+=a[p].s-1;
            a[p].s=1;
        }
        p=a[p].n;
    }
    for(int i=1;i<=n;i++) ans+=a[i].w*a[i].w;
    printf("%lld\n",ans);
    return 0;
}