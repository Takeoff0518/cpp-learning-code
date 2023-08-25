#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (50005)
#define M (500005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
struct E{
	int nxt,to,dis;
	bool f;
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
int pre[N];
void dij(){
	memset(dis,0x3f,sizeof(dis));
	memset(pre,-1,sizeof(pre));
	dis[1]=0; q.push((node){1,0});
	while(!q.empty()){
		int t=q.top().pos; q.pop();
        if(vis[t]) continue;
        vis[t]=1;
        for(int i=h[t];i;i=e[i].nxt){
            int j=e[i].to;
            if(dis[j]>=dis[t]+e[i].dis){
                dis[j]=dis[t]+e[i].dis;
                pre[j]=i;
                if(!vis[j]) q.push((node){j,dis[j]});
            }
        }
	}
}
//void print(int u){
//	if(pre[u]!=-1){
//		print(pre[u]);
//		printf("%d->%d",pre[u],u);
//	}
//}
int main(){
	freopen("distree.in","r",stdin);
	freopen("distree.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
	}
	dij();
	ll ans=0;
//	for(int i=1;i<=n;i++){
//		printf("%d ",dis[i]);
//	} 
//	puts("");
//	for(int i=2;i<=n;i++){
//		print(i);
//		puts("");
//	}
	for(int i=1;i<=n;i++){
		e[pre[i]].f=1;
	}
	for(int i=1;i<=idx;i++){
		if(e[i].f) ans+=e[i].dis; 
	} 
	printf("%lld\n",ans);
	return 0;
}

