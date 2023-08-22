#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (200005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,s,t;
struct E{
    int nxt,to,dis;
}edge[N<<2];
int head[N*7],num_edge;
void add(int from,int to,int dis){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    edge[num_edge].dis=dis;
    head[from]=num_edge;
}
struct node{
	int pos,dis;
	bool operator < (const node &x) const{
		return x.dis<dis;
	}
};
priority_queue<node> q;
int dis[N*7]; bool vis[N*7];
void dij(){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	q.push((node){s,0});
	while(!q.empty()){
		int t=q.top().pos; q.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(int i=head[t];i;i=edge[i].nxt){
			int j=edge[i].to;
			if(dis[j]>dis[t]+edge[i].dis){
				dis[j]=dis[t]+edge[i].dis;
				if(!vis[j]) q.push((node){j,dis[j]});
			}
		}
	}
}
int main(){
//	freopen("day.in","r",stdin);
//	freopen("day.out","w",stdout);
	scanf("%d %d %d %d",&n,&m,&s,&t);
	for(int i=1;i<=n;i++){
		for(int j=2;j<=7;j++){
			add(i*j/2,i*j,1);
		}
	}
	for(int i=1;i<=n;i++){
		add(i*7,i,1);
	}
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add(u*w,v*(w%7+1),1);
	}
	dij();
	int minn=INF;
	for(int i=1;i<=7;i++){
		minn=min(minn,dis[t*i]);
	}
	printf("%d\n",minn!=INF ? minn : -1);
	return 0;
}
