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
ll x;
int _0x0005=0;
int main(){
	cin>>x;
	cout<<x<<' ';
//	cout<<"0:"<<x<<endl;
	while(x!=1){
		_0x0005++;
		if(x%2==0) x/=2;
		else x=x*3+1;
		cout<<x<<' ';
//		cout<<cnt<<":"<<x<<endl;
	}
    return 0;
}
//F**k CCF!!!!!

