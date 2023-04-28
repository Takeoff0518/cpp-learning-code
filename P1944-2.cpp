#include<algorithm>
#include<iostream>	
#include<cstring> 
#include<cstdio>
#define ll long long
const int N=1000005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
char s[N];
int n,f[N],ans,id;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=2;i<=n;++i)
		if((s[i]==')' && s[i-f[i-1]-1]=='(')
		||(s[i]==']' && s[i-f[i-1]-1]=='[')){
			f[i]=f[i-1]+2+f[i-f[i-1]-2];
			if(f[i]>ans){
				ans=f[i],id=i;
			} 
		}
	for(int i=id-ans+1;i<=id;++i){
		printf("%c",s[i]);
	}
	return 0;
}
