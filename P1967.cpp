#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (10005)
#define M (50005)
#define logN (15)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,qq;
struct E{
	int nxt,to;
}edge[8*M];
int head[2*N],num_edge;
void add(int from,int to){
	num_edge++;
	edge[num_edge].nxt=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}
struct node{
	int u,v,w;
	bool operator < (const node &x) const{
		return x.w<w;
	}
}s[M];
int rd(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int fa[2*N];
inline void init(int x){
	for(int i=1;i<=x;i++) fa[i]=i;
}
int findfa(int x){
	if(x!=fa[x]) fa[x]=findfa(fa[x]);
	return fa[x];
}
int val[2*N];
void ex_kruskal(){
	sort(s+1,s+m+1);
	int cnt=n;
	init(2*n);
	for(int i=1;i<=m;i++){
		int u=s[i].u,v=s[i].v,w=s[i].w;
		if(findfa(u)!=findfa(v)){
			cnt++;
			int fa_u=findfa(u),fa_v=findfa(v); 
			add(cnt,fa_u); add(fa_u,cnt);
			add(cnt,fa_v); add(cnt,fa_v);
			val[cnt]=w;
			fa[fa_u]=fa[fa_v]=cnt;
		}
//		if(cnt==2*n-1) break;
	}
}
queue<int> q;
int f[2*N][logN+1],dep[2*N];
void bfs(int root){
	q.push(root);
	dep[0]=0,dep[root]=1;
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int i=head[t];i;i=edge[i].nxt){
			int j=edge[i].to;
			if(dep[j]>dep[t]+1){
				dep[j]=dep[t]+1;
				q.push(j);
				f[j][0]=t;
				for(int k=1;k<=logN;k++){
					f[j][k]=f[f[j][k-1]][k-1];
				}
			}
		}
	}
}
int lca(int a,int b){
	if(dep[a]<dep[b]) swap(a,b);
	for(int k=logN;k>=0;k--)
		if(dep[f[a][k]]>=dep[b])
			a=f[a][k];
	if(a==b) return a;
	for(int k=logN;k>=0;k--)
		if(f[a][k]!=f[b][k])
			a=f[a][k],b=f[b][k];
	return f[a][0];
}
int main(){
	n=rd(); m=rd();
	for(int i=1;i<=m;i++){
		s[i].u=rd(); s[i].v=rd(); s[i].w=rd();
	}
	ex_kruskal();
	memset(dep,0x3f,sizeof(dep));
	for(int i=1;i<=n;i++)
		if(dep[findfa(i)]==INF) bfs(findfa(i));
	qq=rd();
	while(qq--){
		int x=rd(),y=rd();
		if(findfa(x)!=findfa(y)) printf("-1\n");
		else printf("%d\n",val[lca(x,y)]); 
	}
    return 0;
}
//F**k CCF!!!!!

