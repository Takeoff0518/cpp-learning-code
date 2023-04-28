#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (305)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,t,q;
int g[N][N],f[N][N];
int main(){
	memset(g,0x3f,sizeof(g));
	scanf("%d %d %d",&n,&m,&t);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		g[u][v]=g[v][u]=w;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(g[i][j]<=t) f[i][j]=1;
			else f[i][j]=INF; 
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]); 
	scanf("%d",&q);
	while(q--){
		int u,v;
		scanf("%d %d",&u,&v);
		if(f[u][v]!=INF) printf("%d\n",f[u][v]-1);
		else printf("-1\n");
	}
    return 0;
}
//F**k CCF!!!!!

