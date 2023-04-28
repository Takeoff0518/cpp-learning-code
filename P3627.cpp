#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
#define ll long long
#define PII pair<int,int>
const int N=500005,M=500005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m,v[N],u[N],w[N],money[N],bar[N],ans;
struct Edge{
	int nxt,to,dis;
}edge[M];
int head[N],num_edge;
void add(int from,int to,int dis){
	num_edge++;
	edge[num_edge].nxt=head[from];
	edge[num_edge].to=to;
	edge[num_edge].dis=dis;
	head[from]=num_edge;
}
int low[N],dfn[N],sum[N],timestamp,scc_cnt,id[N];
bool in_stk[N]; 
stack<int> st;
void tarjan(int u){
	dfn[u]=low[u]=++timestamp;
	st.push(u);in_stk[u]=1;
	for(int i=head[u];i;i=edge[i].nxt){
		int j=edge[i].to;
		if(!dfn[j]){
			tarjan(j);
			low[u]=min(low[u],low[j]);
		}else if(in_stk[j]){
			low[u]=min(low[u],dfn[j]);
		}
	}
	if(dfn[u]==low[u]){
		int y;
		scc_cnt++;
		do{
			y=st.top();st.pop();
			sum[scc_cnt]+=money[y];
			in_stk[y]=0,id[y]=scc_cnt;
		}while(y!=u);
	}
}
int dis[N];
bool vis[N];
int s,p;
queue<int> q;
void spfa(){
	memset(dis,-0x3f,sizeof(dis));
	int ts=id[s];
	dis[ts]=sum[ts],vis[ts]=1;
	q.push(ts);
	while(!q.empty()){
		int u=q.front(); q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[v]<dis[u]+edge[i].dis){
				dis[v]=dis[u]+edge[i].dis;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u[i],&v[i]);
		add(u[i],v[i],0); 
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&money[i]);
	}
	scanf("%d %d",&s,&p);
	for(int i=1;i<=p;i++){
		scanf("%d",&bar[i]);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	num_edge=0;
	memset(head,0,sizeof(head));
	for(int i=1;i<=m;i++){
		if(id[u[i]]!=id[v[i]]){
			add(id[u[i]],id[v[i]],sum[id[v[i]]]);
		}
	}
	spfa();
	for(int i=1;i<=p;i++){
		if(dis[id[bar[i]]]>ans)
			ans=dis[id[bar[i]]];
	}
	printf("%d\n",ans);
    return 0;
}
//F**k CCF!!!!!

