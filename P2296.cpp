#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (10005)
#define M (200005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
/*
	路径上的所有点的出边所指向的点都直接或间接与终点连通。
	在满足条件 1 的情况下使路径最短。
*/
int n,m,s,t;
struct E{
	int nxt,to;
}e[M],ex[M];
int h[N],hx[N],idx,idxx;
void add(int from,int to){
	e[++idx].nxt=h[from];
	e[idx].to=to;
	h[from]=idx;
}
void addx(int from,int to){
	ex[++idxx].nxt=hx[from];
	ex[idxx].to=to;
	hx[from]=idxx;
}
bool visx[N];
void bfsx(){
	queue<int> q;
	q.push(t);
	while(!q.empty()){
		int t=q.front(); q.pop();
		if(visx[t]) continue;
		visx[t]=1;
		for(int i=hx[t];i;i=ex[i].nxt){
			int j=ex[i].to;
			if(!visx[j]) q.push(j);
		}
	}
}
bool vis[N]; int dis[N];
bool ok[N];
void solve(){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int t=q.front(); q.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(int i=h[t];i;i=e[i].nxt){
			int j=e[i].to;
//			if(!(vis[j] && visx[j])) continue;
			if(!ok[j]) continue;
			if(dis[j]>dis[t]+1){
				dis[j]=dis[t]+1;
				if(!vis[j]) q.push(j);
			}
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		add(u,v); addx(v,u);
	}
	scanf("%d %d",&s,&t);
	bfsx();
//	for(int i=1;i<=n;i++){
//		printf("%d ",visx[i]);
//	}puts("");
//	for(int i=1;i<=n;i++){
//		printf("%d ",ok[i]);
//	}puts("");
	for(int i=1;i<=n;i++){
		ok[i]=1;
		if(!visx[i]) continue;
		for(int t=h[i];t;t=e[t].nxt){
			int j=e[t].to;
			if(!visx[j]){
				ok[i]=0;
				break;
			}
		}
	}
	solve();
	printf("%d\n",dis[t]==INF ? -1 : dis[t]);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

