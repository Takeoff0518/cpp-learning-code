#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll unsigned long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int main(){
	ll ans=0,n,k;
	scanf("%lld %lld",&n,&k);
	k^=(k/2);
	if(n==64){
		cout<<"1000000000000000000000000000000000000000000000000000000000000000"<<endl;
		return 0;
	}
	while(~(--n)){
		cout<<((k>>n)&1);
	}
    return 0;
}

