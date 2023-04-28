#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll unsigned long long
const int N=10005,M=1005;
const int INF=0x3f3f3f3f;
const ll mod=212370440130137957ll,mod2=19260817,base=131;
using namespace std;
ll hashs(char str[]){
	ll h=0;
	for(int i=0;str[i];i++){
		h=(h*base+(ll)(str[i]-'A'+1))%mod;
	}
	return h;
}
ll a[N];
int n,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char s[N];
		scanf("%s",s);
		a[i]=hashs(s);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]) ans++;
	}
	printf("%d\n",ans+1);
    return 0;
}
//F**k CCF!!!!!

