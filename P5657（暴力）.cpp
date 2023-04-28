#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll unsigned long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
void solve(ll n,ll k,ll cnt){
	if(n==1 && k==0){
		printf("0");
		return;
	}
	if(n==1 && k==1){
		printf("1");
		return;
	}
	if(n==2){
		switch(k){
		
			case 0:
				printf("00");
				break;
			case 1:
				printf("01");
				break;
			case 2:
				printf("11");
				break;
			case 3:
				printf("10");
				break;
		}
		return;
	}
	if(k<=cnt/2){
		cout<<"0";
		solve(n-1,k,cnt/2);
	}else{
		cout<<"1";
		solve(n-1,cnt-k+1,cnt/2);
	}
}
bool tmp[N];
int sum=0;
int main(){
	ll n,k,cnt;
	scanf("%lld %lld",&n,&k);
	cnt=1<<(n-1);
	solve(n,k,cnt);
	
    return 0;
}


