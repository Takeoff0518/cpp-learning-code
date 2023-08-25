#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
#define N (1000005)
#define M (1000005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
ll a[N];
int u[N],v[N];
struct Node{
	int nxt,to;
	ll dis;
}e[M];
int h[N],idx;
void add(int from,int to,ll dis){
	e[++idx].nxt=h[from];
	e[idx].to=to;
	e[idx].dis=dis;  // ¾¯ÖÓÇÃÀÃ 
	h[from]=idx;
}
int low[N],dfn[N],timestamp,scc_cnt,id[N];
ll sum[N];
bool in_stk[N]; 
stack<int> st;
ll dis[N];
bool vis[N];
int in[N],out[N];
int out_tong[N],out_idx;
ll ans=0;
void tarjan(int u){
	dfn[u]=low[u]=++timestamp;
	st.push(u);in_stk[u]=1;
	for(int i=h[u];i;i=e[i].nxt){
		int j=e[i].to;
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
			sum[scc_cnt]+=a[y];
			in_stk[y]=0,id[y]=scc_cnt;
		}while(y!=u);
	}
}
void spfa(int s){
	memset(dis,-0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int> q;
	dis[s]=sum[s],vis[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front(); q.pop();
		vis[u]=0;
//		printf("goto: %d\n",u);
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].to;
//			printf("->%d\n",v);
			if(dis[v]<dis[u]+e[i].dis){
				dis[v]=dis[u]+e[i].dis;
//				printf("e[%d].dis=%d\n",i,e[i].dis);
//				printf("upd: dis->%d\n",dis[v]);
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
ll cou(){
	ll maxx=0;
	for(int i=1;i<=out_idx;i++){
		maxx=max(maxx,dis[out_tong[i]]);
//		printf("out[%d]=0, maxx->%d\n",i,maxx);
	}
	return maxx;
}
int main(){
	freopen("mineral.in","r",stdin);
	freopen("mineral.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u[i],&v[i]);
		add(u[i],v[i],0);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	idx=0;
	memset(h,0,sizeof(h));
	for(int i=1;i<=m;i++){
		if(id[u[i]]!=id[v[i]]){
			add(id[u[i]],id[v[i]],sum[id[v[i]]]);
			in[id[v[i]]]++;
			out[id[u[i]]]++;
			// debug
//			printf("add: %d->%d, dis=%d\n",id[u[i]],id[v[i]],sum[id[v[i]]]);
		}
	}
	
	for(int i=1;i<=scc_cnt;i++){
		if(!out[i]) out_tong[++out_idx]=i;
	}
	for(int i=1;i<=scc_cnt;i++){
		if(!in[i]){
			spfa(i);
			ans=max(ans,cou());
//			printf("run: %d, get ans=%d\n",i,ans);
//			puts("dis:");
//			for(int i=1;i<=m;i++){
//				printf("%d ",dis[i]);
//			}
//			puts("");
		}
	}
	printf("%lld\n",ans);
	return 0;
}

