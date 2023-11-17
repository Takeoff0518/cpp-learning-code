#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define N (20005)
#define M (200005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
struct E{
	int nxt,to;
}e[M];
int h[N],idx;
void add(int from,int to){
	e[++idx].nxt=h[from];
	e[idx].to=to;
	h[from]=idx;
}
int dfn[N],low[N],timestamp;
bool is_cut[N];
vector<int> cut;
void tarjan(int u,int fa){
	low[u]=dfn[u]=++timestamp;
	int child=0;
	for(int i=h[u];i;i=e[i].nxt){
		int j=e[i].to;
		if(!dfn[j]){
			tarjan(j,u);
			low[u]=min(low[u],low[j]);
			if((low[j]>=dfn[u] && u!=fa)||(u==fa && ++child>1)){
				is_cut[u]=1;
			}
		}else if(j!=fa){
			low[u]=min(low[u],dfn[j]);
		}
	}
}
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		add(u,v); add(v,u);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,i);
	for(int i=1;i<=n;i++) if(is_cut[i]) cut.push_back(i);
	printf("%d\n",(int)cut.size());
	for(int i:cut){
		printf("%d ",i);
	}
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

