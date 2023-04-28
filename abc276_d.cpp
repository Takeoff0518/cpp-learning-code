#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,a[N],minn=INF;
bool f1=1,f2=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]%2 && a[i]%3 && a[i]>1) f2=1;
		if(i>1 && a[i-1]!=a[i]) f1=0;
		minn=min(minn,a[i]);
	}
	if(f1){puts("0"); return 0;}
	if(f2){puts("-1"); return 0;}
    return 0;
}
//F**k CCF!!!!!

