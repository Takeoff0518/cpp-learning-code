#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (500005)
#define M (1000005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,s;
struct E{
	int nxt,to;
}e[M];
int h[N],idx;
void add(int from,int to){
	e[++idx].nxt=h[from];
	e[idx].to=to;
	h[from]=idx;
}
int fa[N][31],dep[N];
queue<int> q;
void bfs(int root){
	memset(dep,0x3f,sizeof(dep));
	dep[0]=0,dep[root]=1;
	q.push(root);
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int i=h[t];i;i=e[i].nxt){
			int j=e[i].to;
			if(dep[j]>dep[t]+1){
				dep[j]=dep[t]+1;
				q.push(j);
				fa[j][0]=t;
				for(int k=1;k<=30;k++){
					fa[j][k]=fa[fa[j][k-1]][k-1];
				}
			}
		}
	}
}
int lca(int a,int b){
	if(dep[a]<dep[b]) swap(a,b);
	for(int k=30;k>=0;k--){
		if(dep[fa[a][k]]>dep[a]) a=fa[a][k];
	}
	if(a==b) return a;
	for(int k=30;k>=0;k--){
		if(fa[a][k]!=fa[b][k]) a=fa[a][k],b=fa[b][k];
	}
	return fa[a][0];
}
int main(){
	scanf("%d %d %d",&n,&m,&s);
	for(int i=1,u,v;i<=n-1;i++){
		scanf("%d %d",&u,&v);
		add(u,v); add(v,u);
	}
	bfs(s);
	while(m--){
		int u,v;
		scanf("%d %d",&u,&v);
		printf("%d\n",lca(u,v));
	}
    return 0;
}

