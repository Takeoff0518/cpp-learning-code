#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int main(){
	ll n;
	cin>>n;
	while(n%2==0 && n) n/=2;
//	cout<<n<<endl;
	while(n%3==0 && n) n/=3;
//	cout<<n<<endl;
	if(n==1) puts("Yes");
	else puts("No");
    return 0;
}

