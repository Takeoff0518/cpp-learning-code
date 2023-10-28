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
int main(){
	int x,y;
	cin>>x>>y;
	if(x<y &&x+2>=y){
		puts("Yes");
	}else if(x>y && x-3<=y){
		puts("Yes");
	}else{
		puts("No");
	}
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

