#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (200005)
#define M (600005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,k,z;
struct node{
	int u,v,w;
}s[M],mst[M];
bool cmp(node x,node y){
	return x.w<y.w;
}
int fa[N];
void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int findfa(int x){
	if(fa[x]!=x) fa[x]=findfa(fa[x]);
	return fa[x];
}
void mer(int x,int y){
	x=findfa(x),y=findfa(y);
	if(x!=y) fa[x]=y;
}
bool check(int x,int y){
	return findfa(x)==findfa(y);
}
int cnt,ans,block,mstidx;
bool tong[N];
int main(){
	freopen("constructure.in","r",stdin);
	freopen("constructure.out","w",stdout);
	scanf("%d %d %d %d",&n,&m,&k,&z);
	init();
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&s[i].u,&s[i].v,&s[i].w);
		if(!check(s[i].u,s[i].v)){
			mer(s[i].u,s[i].v);
		}
	}
	for(int i=1;i<=n;i++) tong[findfa(i)]++;
	for(int i=1;i<=n;i++) block+=tong[i];
	sort(s+1,s+m+1,cmp);
//	for(int i=1;i<=m;i++){
//		printf("%d->%d:%d\n",s[i].u,s[i].v,s[i].w);
//	}
	init();
	for(int i=1;i<=m;i++){
		if(!check(s[i].u,s[i].v)){
			cnt++;
//			ans+=s[i].w;
			mst[++mstidx]=(node){s[i].u,s[i].v,s[i].w};
			mer(s[i].u,s[i].v);
		}
		if(cnt==n-1) break;
	}
//	printf("%d %d\n",block,k);
	ans+=(block-1)*z;
	k-=block-1;
	sort(mst+1,mst+mstidx+1,cmp);
	for(int i=mstidx;i>=1;i--){
		if(mst[i].w>z && k>0){
			k--;
			mst[i].w=z;
		}
		ans+=mst[i].w;
	}
	printf("%d\n",ans);
	return 0;
}
