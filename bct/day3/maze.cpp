#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (200005)
#define M (200005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,k;
int d[N],s[N];
struct E{
    int nxt,to,dis;
}edge[M<<1];
int head[N],num_edge;
void add(int from,int to,int dis){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    edge[num_edge].dis=dis;
    head[from]=num_edge;
}
int dis[N];
int du[N];
bool vis[N];
queue<int> q;
int main(){
//	freopen("maze.in","r",stdin);
//	freopen("maze.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1,ss;i<=k;i++){
		scanf("%d",&s[i]);
//		s[ss]=true;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
	}
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
		du[u]++,du[v]++;
	}
	for(int i=1;i<=n;i++){
		if(du[i]<=d[i]){
			puts("-1");
			return 0;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	q.push(1);
	dis[1]=0,vis[1]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		vis[u]=0;
		for(int i=head[i];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].dis){
				dis[v]=dis[u]+edge[i].dis;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	int ans=INF;
	for(int i=1;i<=k;i++){
		ans=min(ans,dis[s[i]]);
	}
	printf("%d\n",ans);
    return 0;
}


