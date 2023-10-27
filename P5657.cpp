#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll unsigned long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n;
ll ans,k,po[64];
int main(){
    scanf("%d %llu",&n,&k);
    po[0]=1LL;
    for(int i=1;i<64;i++) po[i]=po[i-1]<<1;
	for(int i=n;i>=1;i--){
		ll mid=(po[i]-1)/2;
		if(k<=mid){
			printf("0");
		}else{
			printf("1");
			k=po[i]-1-k;
		}
	} 
	puts("");
    return 0;
}
