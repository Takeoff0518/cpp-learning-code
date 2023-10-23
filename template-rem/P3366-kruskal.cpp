#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (5005)
#define M (200005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
struct node{
	int u,v,w;
	bool operator < (const node &x) const{
		return x.w>w;
	}
}s[M];
int n,m;
int fa[N];
void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int findfa(int x){
	if(x!=fa[x]) fa[x]=findfa(fa[x]);
	return fa[x];
}
void mer(int x,int y){
	fa[findfa(y)]=findfa(x);
}
int main(){
	scanf("%d %d",&n,&m);
	init();
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&s[i].u,&s[i].v,&s[i].w);
	sort(s+1,s+m+1);
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		if(findfa(s[i].u)!=findfa(s[i].v)){
			mer(s[i].u,s[i].v);
			ans+=s[i].w;
			cnt++;
		}
//		if(cnt>=n-1) break;
	}
	if(cnt==n-1) printf("%d\n",ans);
	else printf("orz\n");
    return 0;
}

