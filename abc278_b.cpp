#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int h,m;
bool check(int _h,int _m){
	int hh=_h/10*10+_m/10,mm=_h%10*10+_m%10;
	if(0<=hh && hh<=23 && 0<=mm && mm<=59){
		return 1;
	}
	return 0;
}
int main(){
	cin>>h>>m;
	for(int i=h;i<=24;i++){
		for(int j=(i==h)?m:0;j<=59;j++){
			if(check(i,j)){
				if(i==24) i=0;
				printf("%d %d\n",i,j);
				return 0;
			}
		}
		if(i==24) i=0;
	}
    return 0;
}
//F**k CCF!!!!!

