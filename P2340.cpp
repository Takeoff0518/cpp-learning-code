#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=105,M=200005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m,ans;
int w[N],v[N];
int f[M];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&w[i],&v[i]);
		if(w[i]>0){
			m+=w[i]<<1;
		}
	}
	memset(f,-0x3f,sizeof(f));
	int k=m>>1;
	f[k]=0;
	for(int i=1;i<=k;i++){
		if(w[i]>0){
			for(int j=m;j>=w[i];j--){
				f[j]=max(f[j],f[j-w[i]]+v[i]);
			}
		}else{
			for(int j=0;j<=m-w[i];j++){
				f[j]=max(f[j],f[j-w[i]]+v[i]);
			} 
		}
	}
	for(int i=1;i<=k;i++){
		if(f[i+k]>=0 && i+f[i+k]>ans){
			ans=i+f[i+k];
		}
	}
	printf("%d\n",ans);
    return 0;
}

