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
	int n;
	cin>>n;
	for(int i=n;i<=919;i++){
		if((i/100)*(i/10%10)==i%10){
			cout<<i<<endl;
			break;
		}
	}
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

