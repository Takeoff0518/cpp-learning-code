#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
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
int n,fa[N];
ll lst[N],sum[N];
char str[N];
stack<int> st;
void dfs(int u){
	int t=0;
	if(str[u]==')'){
		if(!st.empty()){
			t=st.top(); st.pop();
			lst[u]=lst[fa[t]]+1; 
		}
	}else st.push(u);
	sum[u]=sum[fa[u]]+lst[u];
	for(int i=h[u];i;i=e[i].nxt)
		dfs(e[i].to);
	if(t) st.push(t);
	else if(!st.empty()) st.pop();
}
int main(){
	scanf("%d",&n);
	scanf("%s",str+1);
	for(int i=2;i<=n;i++){
		scanf("%d",&fa[i]);
		add(fa[i],i);
	}
	dfs(1);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans^=sum[i]*(ll)i;
	}
	printf("%lld\n",ans);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

