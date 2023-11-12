#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (3000005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
ll inv[N];
int n,p; 
int main(){
	scanf("%d %d",&n,&p);
	inv[1]=1;
	for(int i=2;i<=n;i++){
		inv[i]=(ll)(p-p/i)*inv[p%i]%p;
	}
	for(int i=1;i<=n;i++){
		printf("%lld\n",inv[i]);
	}
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

