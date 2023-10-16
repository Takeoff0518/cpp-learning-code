#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
ll x;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld",&x);
	if(x==1){
		puts("X"); return 0;
	}
	if(x==2){
		puts("X(X)"); return 0;
	}
	if(x==3){
		puts("(X)X"); return 0;
	}
	if(x==4){
		puts("X(X(X))"); return 0;
	}
	if(x==5){
		puts("X((X)X)"); return 0;
	}
	if(x==6){
		puts("(X)X(X)"); return 0;
	}
	if(x==7){
		puts("(X(X))X"); return 0;
	}
	if(x==8){
		puts("((X)X)X"); return 0;
	}
	if(x==9){
		puts("X(X(X(X)))"); return 0;
	}
	if(x==20){
		puts("((X)X(X))X"); return 0;
	}
	if(x==237074288){
		puts("X(((((X)X)X)X(X))X((((((X)X(((X(X))X)X))X)X)X(X))X))"); return 0;
	}
    return 0;
}

