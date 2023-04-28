#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
inline int calc(int _a,int _b,int _t){
	return _a+_b/(_t+1);
}
int n,m;
struct E{
    int nxt,to,v;
}edge[M];
int head[N],num_edge;
void add(int from,int to,int dis){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    edge[num_edge].v=dis;
    head[from]=num_edge;
}
queue<int> q;
int dis[N]; bool vis[N];
void spfa(int s){
	memset(dis,0x3f,sizeof(dis));
	q.push(s);
	dis[s]=0,vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].v){
				dis[v]=dis[u]+edge[i].v;
				if(vis[v]==0){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int u[N],v[N],a[N],b[N];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d %d",&u[i],&v[i],&a[i],&b[i]);
		add(u[i],v[i],a[i]); add(v[i],u[i],a[i]);
	}
	spfa(1);
	printf("%d\n",dis[n]);
    return 0;
}
//F**k CCF!!!!!
//T4
