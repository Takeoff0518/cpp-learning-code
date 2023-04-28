#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=100005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m;
char a[N];
int fa[N];
bool ans[N];
inline void init(){ for(int i=1;i<=n;i++) fa[i]=i;}
int findfa(int x){ if(x!=fa[x]) fa[x]=findfa(fa[x]); return fa[x];}
inline void unionn(int x,int y){ x=findfa(x),y=findfa(y); if(x!=y) fa[x]=y;}
inline bool check(int x,int y){ return findfa(x)==findfa(y);};
int main(){
	memset(ans,1,sizeof(ans));
	scanf("%d %d",&n,&m);
	scanf("%s",a+1);
	init();
	for(int i=1,u,v;i<=n-1;i++){
		scanf("%d %d",&u,&v);
		if(a[u]==a[v]) unionn(u,v);
	}
	for(int i=1,u,v;i<=m;i++){
		char c[5];
		scanf("%d %d",&u,&v);
		scanf("%s",c);
		if(check(u,v) && a[u]!=c[0]) ans[i]=0;
	}
	for(int i=1;i<=m;i++) printf("%d",ans[i]);
    return 0;
}
//F**k CCF!!!!!

