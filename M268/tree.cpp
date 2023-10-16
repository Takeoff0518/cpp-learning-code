#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (10005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (1000000007)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
#define db puts("debug")
using namespace std;
int n,m;
int ans;
int su[N],sv[N];
bool sx[N];
struct E{
	int nxt,to;
	bool dis;
}e[M<<1];
int h[N],idx;
void add(int from,int to){
	idx++;
	e[idx].nxt=h[from];
	e[idx].to=to;
	e[idx].dis=0;
	h[from]=idx;
}
bool vis[N]; bool dis[N][N];
// O(n)
queue<int> q; 
void bfs(int s,bool *d,int id){
	queue<int>().swap(q);
	for(int i=1;i<=n;i++) vis[i]=0,d[i]=0;
	q.push(s);
	while(!q.empty()){
		int t=q.front(); q.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(int i=h[t];i;i=e[i].nxt){
			// db;
			int j=e[i].to;
			d[j]=(d[t]+e[i].dis)&1;
			if(!vis[j]) q.push(j);
			if(t==sv[id]) return;
		}
	}
}
// O(2^n)
void gen(int x){
	if(x==n){
		for(int i=1;i<=m;i++)
			// O(q)
			bfs(su[i],dis[su[i]],i);
		for(int i=1;i<=m;i++)
			if(dis[su[i]][sv[i]]!=sx[i]){
				return;
			}
		ans++;
		ans%=mod;
		return;
	}
	e[x*2-1].dis=e[x*2].dis=1;
	gen(x+1);
	e[x*2-1].dis=e[x*2].dis=0;
	gen(x+1);
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<n;i++){
		scanf("%d %d",&u,&v);
		add(u,v); add(v,u);
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&su[i],&sv[i],&sx[i]);
	}
	gen(1);
	printf("%d\n",ans);
    return 0;
}

