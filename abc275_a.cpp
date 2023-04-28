#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,a[N];
int main(){
	cin>>n;
	int maxx=-INF,maxi=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxx){
			maxx=a[i];
			maxi=i;
		}
	}
	cout<<maxi<<endl;
    return 0;
}
//F**k CCF!!!!!

