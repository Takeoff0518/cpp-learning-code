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
int t,id,n,m,cc,ff;
int ans_c,ans_f;
bool g[N][N];
/*
 ----> y,i
|
|
|
x,j

*/
int f[N][N];
void solve(){
	scanf("%d %d %d %d",&n,&m,&cc,&ff);
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		char s[N];
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			g[i][j]=s[j]=='1' ? 1 : 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=m-1;j>=1;j--){
			if(g[i][j]==1) f[i][j]=-1;
			else if(g[i][j+1]==0) f[i][j]=f[i][j+1]+1;
		} 
	}
	for(int j=1;j<=m-1;j++){
		int cl=0,clf=0;
		for(int i=1;i<=n;i++){
			if(f[i][j]==-1){
				cl=clf=0;
				continue;	
			}
			ans_f=(ans_f+clf,ans_c+=f[i][j]*cl)%mod;
			ans_c=(ans_c+f[i][j]*(cl%mod))%mod;
			clf+=f[i][j]*cl;
			cl+=max(0,f[i-1][j]);
		}
	}
}
int main(){
	scanf("%d %d",&t,&id);
	memset(g,1,sizeof(g));
	while(t--) solve();
	
    return 0;
}

