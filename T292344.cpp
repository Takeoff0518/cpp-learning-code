#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int mod=998244353;
using namespace std;
ll n,m,ans;
int main(){
	scanf("%lld %lld",&n,&m);
	ans=(n-1)+n*(m-1);
	printf("%lld\n",ans);
    return 0;
}
//F**k CCF!!!!!

