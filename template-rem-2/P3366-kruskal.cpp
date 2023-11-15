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
int n,m;
struct E{
	int u,v,w;
	bool operator < (const E &x) const{
		return x.w>w;
	}
}s[M];
int fa[N];
int findfa(int x){
	if(x!=fa[x]) fa[x]=findfa(fa[x]);
	return fa[x];
}
void mer(int x,int y){
	x=findfa(x),y=findfa(y);
	if(x!=y) fa[x]=y;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&s[i].u,&s[i].v,&s[i].w);
	}
	sort(s+1,s+m+1);
	int ans=0,cnt=0;
	for(int i=1;i<=m;i++){
		int x=s[i].u,y=s[i].v;
		if(findfa(x)!=findfa(y)){
			mer(x,y);
			ans+=s[i].w;
			cnt++;
		}
		if(cnt>=n-1) break;
	}
	if(cnt<n-1) printf("orz");
	else printf("%d\n",ans);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

