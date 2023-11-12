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
int n,a,b;
int main(){
	cin>>n>>a>>b;
	if(a>n/2){
		for(int i=1;i<n;i++) cout<<'D';
		for(int i=1;i<=n-a;i++) cout<<'U';
	}else{
		for(int i=1;i<n;i++) cout<<'U';
		for(int i=1;i<=n-a;i++) cout<<'D';
	}
	if(b>n/2){
		for(int i=1;i<n;i++) cout<<'R';
		for(int i=1;i<=n-b;i++) cout<<'L';
	}else{
		for(int i=1;i<n;i++) cout<<'L';
		for(int i=1;i<=n-b;i++) cout<<'R';
		
	}
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

