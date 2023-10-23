#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue> 
#define N (100005)
#define M (200005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,s;
struct E{
	int nxt,to,dis;
}e[M];
int h[N],idx;
void add(int from,int to,int dis){
	e[++idx].nxt=h[from];
	e[idx].to=to;
	e[idx].dis=dis;
	h[from]=idx;
}
struct node{
	int pos,dis;
	bool operator < (const node &x) const{
		return x.dis<dis;
	}
};
priority_queue<node> q;
int dis[N]; bool vis[N];
void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0; q.push({s,0});
	while(!q.empty()){
		int t=q.top().pos; q.pop();
		if(vis[t]) continue; vis[t]=1;
		for(int i=h[t];i;i=e[i].nxt){
			int j=e[i].to;
			if(dis[j]>dis[t]+e[i].dis){
				dis[j]=dis[t]+e[i].dis;
				if(!vis[j]) q.push({j,dis[j]});
			} 
		}
	}
}
int main(){
	scanf("%d %d %d",&n,&m,&s);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
	}
	dijkstra();
	for(int i=1;i<=n;i++) printf("%d ",dis[i]);
	puts("");
    return 0;
}

