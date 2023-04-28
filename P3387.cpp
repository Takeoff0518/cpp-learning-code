#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#define ll long long
#define INF (0x3f3f3f3f)
#define N (10005)
#define M (100005)
#define MOD (998244353)
#define ls(_p) (_p)<<1
#define rs(_p) (_p)<<1|1
using namespace std;
int n,m,a[N],u[N],v[N];
struct E{
    int nxt,to;
}e[M];
int h[N],ne;
void add(int from,int to){
	ne++;
	e[ne].nxt=h[from];
	e[ne].to=to;
	h[from]=ne;
}
int dfn[N],low[N],timestamp,id[N],scc_cnt,sum[N];
stack<int> st; bool in_stk[N];
queue<int> q;
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
			sum[scc_cnt]+=a[y];
			in_stk[y]=0,id[y]=scc_cnt;
		}while(y!=u);
	}
}
int in[N],f[N],ans=-INF;
void DAG(){
//	memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++){
		if(!in[i]) q.push(i);
//x		printf("push:%d\n",i);
		if(f[i]==0) f[i]=sum[i];
	}
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int i=h[t];i;i=e[i].nxt){
			int j=e[i].to; in[j]--;
			f[j]=max(f[j],f[t]+sum[j]);
			if(in[j]==0) q.push(j);
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
}
int main(){
    scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u[i],&v[i]);
        add(u[i],v[i]);
    }
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	ne=0; memset(h,0,sizeof(h));
	for(int i=1;i<=m;i++){
		if(id[u[i]]!=id[v[i]]){
			add(id[u[i]],id[v[i]]);
//			printf("add %d->%d(p:%d->%d)\n",id[u[i]],id[v[i]],u[i],v[i]);
			in[id[v[i]]]++;
		}
	}
	DAG();
	printf("%d\n",ans);
    return 0;
}