#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#define ll long long
#define PII pair<int,int>
const int N=100005,M=500005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
struct E{
	int nxt,to;
}edge[M];
int head[N],num_edge;
void add(int from,int to){
	num_edge++;
	edge[num_edge].nxt=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}
int n,m,ans;
bool nt[N];
int dfn[N],low[N],timestamp,id[N],scc_cnt;
bool in_stk[N];stack<int> st; 
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
			in_stk[y]=0,id[y]=scc_cnt;
		}while(y!=u);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		add(u,v);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	for(int u=1;u<=n;u++){
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(id[u]!=id[v])
				nt[id[v]]=1;
		}
	}
	for(int i=1;i<=scc_cnt;i++)
		if(!nt[i]) ans++;
	printf("%d\n",ans); 
    return 0;
}
//F**k CCF!!!!!

