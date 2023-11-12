#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#define N (200005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
string s;
char st[N];
int pos;
int main(){
	cin>>s;
	for(char c:s){
		if(c=='C' && st[pos]=='B' && st[pos-1]=='A'){
			pos-=2;
		}else{
			st[++pos]=c;
		}
	}
	for(int i=1;i<=pos;i++){
		cout<<st[i];
	}
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

