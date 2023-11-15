#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#define N (500005)
#define M (500005)
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
int n,m;
int dfn[N],low[N],timestamp,sum[N],id[N],scc_cnt;
stack<int> st; bool in_st[N];
int a[N];
void tarjan(int u){
	dfn[u]=low[u]=++timestamp;
	st.push(u); in_st[u]=1;
	for(int i=h[u];i;i=e[i].nxt){
		int j=e[i].to;
		if(!dfn[j]){
			tarjan(j);
			low[u]=min(low[u],low[j]);
		}else if(in_st[j])
			low[u]=min(low[u],dfn[j]);
	}
	if(low[u]==dfn[u]){
		int y; scc_cnt++;
		do{
			y=st.top(); st.pop();
			in_st[y]=0;
			sum[scc_cnt]+=a[y];
			id[y]=scc_cnt;
		}while(y!=u);
	}
}
int su[N],sv[N];
int inv[N];
queue<int> q;
int f[N];
void dag(){
	for(int i=1;i<=scc_cnt;i++){
		if(!inv[i]) q.push(i);
		f[i]=sum[i];
	}
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int i=h[t];i;i=e[i].nxt){
			int j=e[i].to;
			f[j]=max(f[j],f[t]+sum[j]);
			inv[j]--;
			if(!inv[j]) q.push(j);
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&su[i],&sv[i]);
		add(su[i],sv[i]);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	memset(h,0,sizeof(h)); idx=0;
	for(int i=1;i<=m;i++)
		if(id[su[i]]!=id[sv[i]]){
			add(id[su[i]],id[sv[i]]);
			inv[id[sv[i]]]++;
		}
	dag();
	int ans=0;
	for(int i=1;i<=scc_cnt;i++)
		ans=max(ans,f[i]);
	printf("%d\n",ans); 
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

