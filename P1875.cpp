#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n;
int dis[N],cnt[N];
bool vis[N];
int g[N][N];
void dijkstra(){
	// memset(dis,0x3f,sizeof(dis));
	// dis[1]=0;
	for(int i=1;i<=n;i++){
		int t=INF,u;
		for(int j=1;j<=n;j++){
			if(!vis[j] && dis[j]<t){
				t=dis[j];
				u=j;
			}
		}
		if(t==INF) break;
		vis[u]=1;
		for(int j=1;j<=n;j++){
			if(!g[u][j]) continue;
			if(!vis[j]) continue;
			if(dis[g[u][j]]>t+dis[j]){
				dis[g[u][j]]=t+dis[j];
				cnt[g[u][j]]=cnt[u]*cnt[j];
			}else if(dis[g[u][j]]==t+dis[j]){
				cnt[g[u][j]]+=cnt[u]*cnt[j];
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&dis[i]);
		cnt[i]=1;
	}
	int u,v,w;
	while(scanf("%d %d %d",&u,&v,&w)!=EOF){
		g[u+1][v+1]=g[v+1][u+1]=w+1;
	}
	dijkstra();
	printf("%d %d\n",dis[1],cnt[1]);
    return 0;
}
//F**k CCF!!!!!

