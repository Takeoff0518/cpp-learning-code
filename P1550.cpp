#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n;
struct E{
	int u,v,w;
	bool operator< (const E &x) const{
		return x.w>w;
	}
}s[100005];
int idx;
int fa[1005];
int findfa(int x){
	if(x!=fa[x]) fa[x]=findfa(fa[x]);
	return fa[x];
}
void mer(int x,int y){
	x=findfa(x),y=findfa(y);
	if(x!=y) fa[x]=y;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n*2+1;i++) fa[i]=i;
	for(int i=1,w;i<=n;i++){
		scanf("%d",&w);
		s[++idx]={i,n+1,w};
	}
	for(int i=1;i<=n;i++){
		for(int j=1,w;j<=n;j++){
//			if(i==j) continue;
			scanf("%d",&w);
			s[++idx]={i,j,w};
		}
	}
	int ans=0,cnt=0;
	sort(s+1,s+idx+1);
	for(int i=1;i<=idx;i++){
		int u=s[i].u,v=s[i].v,w=s[i].w;
		if(findfa(u)!=findfa(v)){
			mer(u,v);
			ans+=w;
			cnt++;
		}
	}
	printf("%d\n",ans);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

