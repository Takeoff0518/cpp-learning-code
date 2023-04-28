#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define PII pair<int,int>
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n;
bool f;
string s[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i][0]!='H' && s[i][0]!='D' && s[i][0]!='C' && s[i][0]!='S'){
//			puts("qwq");
			f=1;
		}
		if(s[i][1]!='A' && s[i][1]!='2' && s[i][1]!='3' && s[i][1]!='4' && s[i][1]!='5' 
		&& s[i][1]!='6' && s[i][1]!='7' && s[i][1]!='8' && s[i][1]!='9' 
		&& s[i][1]!='T' && s[i][1]!='J' && s[i][1]!='Q' && s[i][1]!='K'){
//			puts("qwq");
			f=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(s[i]==s[j]){
				f=1;
				break;
			}
		}
	}
	if(f) puts("No");
	else puts("Yes");
    return 0;
}
//F**k CCF!!!!!

