#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (3005)
#define M (6005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
bool a[N];
struct E{
	int nxt,to;
}e[M];
int h[N],idx;
void add(int from,int to){
	idx++;
	e[idx].nxt=h[from];
	e[idx].to=to;
	h[from]=idx;
}
int ans=INF;
int dep[N];
bool vis[N];
int minn,maxx;
void bfs(int s){
	queue<int> q;
	memset(vis,0,sizeof(vis));
//	memset(dep,0,sizeof(dep));
	q.push(s);
	dep[s]=1;
	int rest=m;
	minn=INF,maxx=-1;
	while(!q.empty()){
		if(!rest) break;
		rest--;
		int t=q.front(); q.pop();
		vis[t]=1;
		if(!a[t]){
			minn=min(minn,dep[t]);
			maxx=max(maxx,dep[t]);
		}
		for(int i=h[t];i;i=e[i].nxt){
			int j=e[i].to;
			if(!vis[j]){
				q.push(j);
				dep[j]=dep[t]+1;
			}
		}
	}
}
int main(){
	freopen("distance.in","r",stdin);
	freopen("distance.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1,u,v;i<n;i++){
		scanf("%d %d",&u,&v);
		add(u,v); add(v,u);
	}
	for(int i=1;i<=n;i++){
		if(!a[i]) bfs(i);
		ans=min(ans,maxx+minn); 
	}
	printf("%d\n",ans);
	return 0;
}

