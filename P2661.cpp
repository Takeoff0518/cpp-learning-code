#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#define N (200005)
#define M (200005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N];
struct E{
	int nxt,to;
}e[M];
int h[N],idx;
void add(int from,int to){
	e[++idx].nxt=h[from];
	e[idx].to=to;
	h[from]=idx;
}
int dfn[N],low[N],timestamp,scc_cnt;
int siz[N];
bool in_stk[N];
stack<int> st;
void tarjan(int u){
	dfn[u]=low[u]=++timestamp;
	st.push(u); in_stk[u]=1;
	for(int i=h[u];i;i=e[i].nxt){
		int j=e[i].to;
		if(!dfn[j]){
			tarjan(j);
			low[u]=min(low[u],low[j]);
		}else if(in_stk[j])
			low[u]=min(low[u],dfn[j]);
	}
	if(low[u]==dfn[u]){
		int y;
		scc_cnt++;
		do{
			y=st.top(); st.pop();
			in_stk[y]=0,siz[scc_cnt]++;
		}while(y!=u);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,t;i<=n;i++){
		scanf("%d",&t);
		add(i,t);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	int ans=INF;
	for(int i=1;i<=scc_cnt;i++){
		if(siz[i]>1) ans=min(ans,siz[i]);
	}
	printf("%d\n",ans);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

