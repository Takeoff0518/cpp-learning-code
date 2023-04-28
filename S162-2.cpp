#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
unsigned ll f[N];
void fun(int n){
	f[1]=f[2]=1;
	for(int i=3;i<=10;i++){
		f[i]=f[i-1]+1ll*f[i-2]*(n-1);
	}
}
int main(){
	for(int i=1;i<=10;i++){
		fun(i);
		for(int j=1;j<=10;j++){
			printf("%d ",f[j]);
		}
		puts("");
	}
    return 0;
}

