#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
char s[105];
int ans=-1;
int main(){
	cin>>s;
	for(int i=0;s[i];i++){
		if(s[i]=='a') ans=i+1; 
	} 
	cout<<ans<<endl;
    return 0;
}
//F**k CCF!!!!!

