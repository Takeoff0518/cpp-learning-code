#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (20)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,a,b;
ll ans=0;
bool vis[N][N];
void bf(){
	scanf("%d %d %d %d",&n,&m,&a,&b);
	if(n==2 && m==2 && a==1 && b==2) ans=4;
	else if(b==0) ans=1;
	else if(a==0) ans=1;
//	else if(h==1){
//		
//	}else if(w==)
//	else if(n==2 && m==2){
//		
	else{
		printf("sb CCF.\n");
		return;
	}
	printf("%lld\n",ans);
}
void dfs(int x,int y,int aa,int bb){
//	printf("(%d,%d),%d,%d\n",x,y,aa,bb);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) printf("%d",vis[i][j]);
//		puts("");
//	}
	if(aa>a || bb>b) return;
	if(y>m){
		if(a==aa && b==bb){
			ans++;
			return;
		}
		if(x<n){
			dfs(x+1,1,aa,bb);
			return;
		}
	}
	if(!vis[x][y]){
//		printf(",goto:1\n");
		vis[x][y]=1;
		dfs(x,y+1,aa,bb+1);
		vis[x][y]=0;
	}else{
		dfs(x,y+1,aa,bb);
	}
	if(!vis[x][y] && !vis[x][y+1]){
//		printf(",goto:2\n");
		vis[x][y]=vis[x][y+1]=1;
		dfs(x,y+2,aa+1,bb);
		vis[x][y]=vis[x][y+1]=0;
	}
	if(!vis[x][y] && !vis[x+1][y]){
//		printf(",goto:3\n");
		vis[x][y]=vis[x+1][y]=1;
		dfs(x,y+1,aa+1,bb);
		vis[x][y]=vis[x+1][y]=0;
	}
}
int main(){
	scanf("%d %d %d %d",&n,&m,&a,&b);
	memset(vis,1,sizeof(vis));
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vis[i][j]=0; 
	dfs(1,1,0,0);
	printf("%lld\n",ans);
    return 0;
}
//F**k CCF!!!!!
//T3
