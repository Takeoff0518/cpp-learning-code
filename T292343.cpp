#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
const int N=300005,M=500005;
const int INF=0x3f3f3f3f;
const int mod=998244353;
using namespace std;
int n,m;
struct E{
	int u,v,w;
	bool operator < (const E &x) const{
		return x.w>w;
	}
	#define u(xxx) s[xxx].u
	#define v(xxx) s[xxx].v
	#define w(xxx) s[xxx].w
}s[M];
int fa[N];
void init(){ for(int i=1;i<=n;i++) fa[i]=i;}
int findfa(int x){ if(x!=fa[x]) fa[x]=findfa(fa[x]); return fa[x];}
inline void unionn(int x,int y){ x=findfa(x),y=findfa(y); if(x!=y) fa[x]=y;}
inline bool check(int x,int y){ return findfa(x)==findfa(y);}
ll kruskal(int nt){
	ll ans=0;
	int cnt=0;
	init();
	for(int i=1;i<=m;i++){
		if(!check(u(i),v(i)) && u(i)!=nt && v(i)!=nt){
			unionn(u(i),v(i));
			cnt++;
			ans+=w(i);
		}
		if(cnt==n-2) break;
	}
	if(cnt!=n-2) return -1;
	else return ans;
}
ll res=0;
int main(){
	freopen("T292343.in","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u(i),&v(i),&w(i));
	}
	sort(s+1,s+m+1);
	for(int i=1;i<=n;i++){
		res+=kruskal(i);
	}
	printf("%lld\n",res);
    return 0;
}
//F**k CCF!!!!!

