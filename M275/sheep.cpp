#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)

#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (1000005)
#define M (1000005)
#define ll long long
#define logN (23)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,qu;
struct E{
	int nxt,to;
}e[M*4];
int h[N<<1],idx;
void add(int from,int to){
	e[++idx].nxt=h[from];
	e[idx].to=to;
	h[from]=idx;
}
struct node{
	int u,v,w;
	bool operator < (const node &x) const{
		return x.w>w;
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
int fa[N<<1];
inline void init(int x){
	for(int i=1;i<=x;i++) fa[i]=i;
}
int findfa(int x){
	if(x!=fa[x]) fa[x]=findfa(fa[x]);
	return fa[x];
}
int val[N<<1];
int cnt;
void ex_kruskal(){
	sort(s+1,s+m+1);
	cnt=n; 
	init(n<<1);
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
	}
}
queue<int> q;
int f[N<<1][logN+1],dep[N<<1];
void bfs(int root){
	q.push(root);
	dep[0]=0,dep[root]=1;
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int i=h[t];i;i=e[i].nxt){
			int j=e[i].to;
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
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	n=rd(); m=rd(); qu=rd();
//	scanf("%d %d %d",&n,&m,&qu);
	for(int i=1;i<=m;i++){
//		scanf("%d %d %d",&s[i].u,&s[i].v,&s[i].w);
		s[i].u=rd(); s[i].v=rd(); s[i].w=rd();
	}
	ex_kruskal();
	memset(dep,0x3f,sizeof(dep));
	for(int i=1;i<=n;i++)
		if(dep[findfa(i)]==INF) bfs(findfa(i));
	while(qu--){
		int x,y,c;
//		scanf("%d %d %d",&x,&y,&c);
		x=rd(); y=rd(); c=rd();
		if(findfa(x)!=findfa(y)) puts("No");
		else if(val[lca(x,y)]<=c) puts("Yes");
		else puts("No"); 
	}
//	printf("%d %d\n",cnt,idx); 
	
    return 0;
}

