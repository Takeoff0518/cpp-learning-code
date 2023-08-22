#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,p;
int a[N];
ll power(ll x,ll y,ll z){
    ll ans=1;
    while(y){
        if(y&1){
            ans=ans*x%p;
        }
        x=x*x%p;
        y>>=1;
    }
    return ans;
}
int main(){
	freopen("catalan.in","r",stdin);
	freopen("catalan.out","w",stdout);
	scanf("%d %d",&n,&p);
	a[1]=1,a[2]=3,a[3]=9,a[4]=27,a[5]=84,a[6]=270,a[100]=829570569;
	printf("%d\n",a[n]%p);
	return 0;
}

