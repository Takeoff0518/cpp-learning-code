#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=10005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,k;
int p[N],t[N],f[N];
bool h[N];
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%d %d",&p[i],&t[i]);
		h[p[i]]=1;
	}
	//f[n+1]=0;
	for(int i=n;i>=1;i--){
		if(h[i]){
			for(int j=1;j<=k;j++){
				if(p[j]==i){
					f[i]=max(f[i+t[j]],f[i]);
				}
			}
		}else{
			f[i]=f[i+1]+1;
		}
	}
	cout<<f[1];
    return 0;
}

