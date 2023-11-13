#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define N (5005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
vector<int> e[N];
PII edge[N]; //记录边的两个端点
int du,dv;//断边位置
bool vis[N];
vector<int> path(N,N);
int cnt;
bool better; 
bool dfs(int u){
	if(!better){//变大回退 
		if(u>path[cnt]) return 1;
		if(u<path[cnt]) better=1;
	}
	vis[u]=1;
	path[cnt++]=u;
	for(int i=0;i<(int)e[u].size();i++){
		int v=e[u][i];
		if(vis[v]) continue;
		if(v==du && u==dv) continue;
		if(v==dv && u==du) continue;
		if(dfs(v)) return true;
	}
	return false;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
		edge[i]={u,v};
	}
	for(int i=1;i<=n;i++){
		sort(e[i].begin(),e[i].end());
	}
	if(n==m+1) dfs(1);
	else{//轮着删边 
		for(int i=1;i<=m;i++){
			du=edge[i].first;
			dv=edge[i].second;
			memset(vis,0,sizeof(vis));
			cnt=better=0; 
			dfs(1);
		}
	}
	for(int i=0;i<n;i++) printf("%d ",path[i]);
	puts("");
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

