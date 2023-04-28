#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue> 
#define N (100005)
#define M (300005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,qu;
//edge
struct E{
	int nxt,to;
}edge[M<<3];
int head[N<<1],num_edge;
void add(int from,int to){
	num_edge++;
	edge[num_edge].nxt=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}
//²¢²é¼¯ 
int fa[N<<1];
inline void init(){ 
	for(int i=1;i<=(n<<1);i++) fa[i]=i;
}
int findfa(int x){
	if(x!=fa[x])
		fa[x]=findfa(fa[x]);
	return fa[x];
}
inline void unionn(int x,int y){
	x=findfa(x),y=findfa(y);
	if(x!=y) fa[x]=y;
}
inline bool check(int x,int y){
	return findfa(x)==findfa(y);
}
//ex_kruskal
struct E2{
	int u,v,w;
	bool operator < (const E2 &x) const{ return x.w>w;}
}s[M];
int val[N<<1];
inline void ex_kruskal(){
	init();
	sort(s+1,s+m+1);
	int cnt=n; 
	for(int i=1;i<=m;i++){
		int u=s[i].u,v=s[i].v,w=s[i].w;
		if(!check(u,v)){
			cnt++;
			int fa_u=findfa(u),fa_v=findfa(v);
			add(cnt,fa_u); add(fa_u,cnt); 
			add(cnt,fa_v); add(fa_v,cnt);
			fa[fa_u]=fa[fa_v]=cnt;
			val[cnt]=w;
//			debug:
// 			printf("add:%d-[%d]%d-%d\n",fa_u,val[cnt],cnt,fa_v);
			if(cnt==(n<<1)-1) break;
		}
	}
//	return cnt;
}
//LCA
int f[N<<1][31],dep[N<<1];
queue<int> q;
void bfs(int root){
//	memset(dep,0x3f,sizeof(dep));
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
				for(int k=1;k<=30;k++)
					f[j][k]=f[f[j][k-1]][k-1];
			}
		}
	}
}
int lca(int a,int b){
//	printf("lca:%d,%d\n",a,b);
	if(dep[a]<dep[b]) swap(a,b);
	for(int k=30;k>=0;k--)
		if(dep[f[a][k]]>=dep[b]){
			a=f[a][k];
//			printf("lca:%d,%d\n",a,b);
		}
	if(a==b) return a;
	for(int k=30;k>=0;k--)
		if(f[a][k]!=f[b][k]){
			a=f[a][k],b=f[b][k];
//			printf("lca:%d,%d\n",a,b);
		}
	return f[a][0];
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&s[i].u,&s[i].v,&s[i].w);
	}
	ex_kruskal();
//	int root=ex_kruskal();
//	printf("root=%d\n",root);
	memset(dep,0x3f,sizeof(dep));
	for(int i=1;i<=n;i++){
		if(dep[findfa(i)]==INF){
//			cout<<"bfs:"<<findfa(i)<<endl;
			bfs(findfa(i));
		}
	}
//	for(int i=1;i<=(n<<1);i++){
//		printf("%d ",dep[i]);
//	}
//	puts("");
//	for(int i=1;i<=(n<<1);i++){
//		printf("%d ",val[i]);
//	}
//	puts("");

	scanf("%d",&qu);
	for(int i=1,u,v;i<=qu;i++){
		scanf("%d %d",&u,&v);
		if(!check(u,v)) printf("impossible\n");
		else{
			int ans=lca(u,v);
// 			printf("%d:",ans);
			printf("%d\n",val[ans]);
		}
	}
    return 0;
}
//F**k CCF!!!!!

