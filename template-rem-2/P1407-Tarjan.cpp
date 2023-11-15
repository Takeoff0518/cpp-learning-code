#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#define N (1005)
#define M (1005)
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
int dfn[N],low[N],timestamp,scc_cnt,id[N];
bool in_st[N];
stack<int> st;
void tarjan(int u){
	dfn[u]=low[u]=++timestamp;
	st.push(u); in_st[u]=1;
	for(int i=h[u];i;i=e[i].nxt){
		int j=e[i].to;
		if(!dfn[j]){
			tarjan(j);
			low[u]=min(low[u],low[j]);
		}else if(in_st[j]){
			low[u]=min(low[u],dfn[j]);
		}
	}
	if(low[u]==dfn[u]){
		int y; scc_cnt++;
		do{
			y=st.top(); st.pop(); in_st[y]=0;
			id[y]=scc_cnt;
		}while(y!=u);
	}
}
int main(){

    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

