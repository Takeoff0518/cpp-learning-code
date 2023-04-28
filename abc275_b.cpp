#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ull unsigned long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
ull a,b,c,d,e,f;
int main(){
	cin>>a>>b>>c>>d>>e>>f;
	cout<<((a*b*c)%p+p-(d*e*f)%p)%p;
    return 0;
}
//F**k CCF!!!!!

