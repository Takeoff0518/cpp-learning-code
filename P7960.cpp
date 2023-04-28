#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<bitset>
#define N (10000005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
bitset<N> vis;
int n,m,t;
int nxt[N];
inline bool p(int xxx){
//	if(xxx%7==0) return 1;
	while(xxx){
		if(xxx%10==7) return 1;
		xxx/=10;
	}
	return 0;
}
void solve(){
	int ls=0,val=0;
	for(int i=1;i<=N;i++){
		if(vis[i]){
			continue;
		}else if(p(i)){
			for(int j=i;j<=N;j+=i){
				vis[j]=1;
			}
		}else{
			nxt[ls]=i;
			ls=i;
		}
	}
}
int read(){
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main(){
	memset(nxt,-1,sizeof(nxt));
	solve();
	scanf("%d",&t);
	while(t--){
		n=read();
		if(vis[n]) printf("-1\n");
		else printf("%d\n",nxt[n]);
	}
    return 0;
}
//F**k CCF!!!!!

