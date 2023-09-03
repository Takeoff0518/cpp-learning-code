#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<stack>
#define N (24005)
#define M (24005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
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
map<string,int> mp;
int q1[N],q2[N],cnt;
int n,m;
int dfn[N],low[N],timestamp,scc_cnt,id[N];
bool in_stk[N];
stack<int> st;
void tarjan(int u){
	dfn[u]=low[u]=++timestamp;
	st.push(u); in_stk[u]=1;
	for(int i=head[u];i;i=edge[i].nxt){
		int j=edge[i].to;
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
			in_stk[y]=0,id[y]=scc_cnt;
		}while(y!=u);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		string from,to;
		cin>>from>>to;
		if(!mp[from]) mp[from]=++cnt;
		if(!mp[to])  mp[to]=++cnt;
		q1[i]=mp[from],q2[i]=mp[to];
		add(q1[i],q2[i]);
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		string from,to;
		cin>>to>>from;
		add(mp[from],mp[to]);
	}
	for(int i=1;i<=cnt;i++){
		if(!dfn[i]) tarjan(i); 
	}
//	for(int i=1;i<=cnt;i++) cout<<id[i]<<' ';
//	cout<<endl;
	for(int i=1;i<=n;i++){
		if(id[q1[i]]==id[q2[i]]) cout<<"Unsafe"<<endl;
		else cout<<"Safe"<<endl;
	}
    return 0;
}
//F**k CCF!!!!!

