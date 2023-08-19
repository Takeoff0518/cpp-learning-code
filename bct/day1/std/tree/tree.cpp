#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define SZ(x) ((int)(x.size()))
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=5e5+5,mod=1e9+7,iv2=(mod+1)/2;
int n,dfn[N],cnt,siz[N],fa[N];

pair<int,int> v[N];

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

inline int MOD(int x)
{
	return x>=mod?x-mod:x;
}

struct BIT
{
	int c[N];
	inline void add(int x,int v)
	{
		for(;x<=n;x+=lowbit(x))
			c[x]=MOD(c[x]+v);
	}
	inline int query(int x)
	{
		int res=0;
		for(;x;x-=lowbit(x))
			res=MOD(res+c[x]);
		return res;
	}
	inline int query(int l,int r)
	{
		return query(r)-query(l-1);
	}
}s0,s1,s2;

void dfs(int u,int F)
{
	dfn[u]=++cnt;fa[u]=F;siz[u]=1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==F) continue;
		dfs(v,u);siz[u]+=siz[v];
	}
}

signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
		v[i]=mp(read(),i);
	sort(v+1,v+n+1);
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int u=v[i].se;
		int res=0;
		for(int j=head[u];j;j=e[j].ne)
		{
			int v=e[j].v;
			if(v==fa[u]) continue;
			int tmp=(s1.query(dfn[v],dfn[v]+siz[v]-1)+mod)%mod;
			res=(res+siz[v]*1ll*(n-1-siz[v])%mod*iv2+siz[v]+tmp*1ll*(n-siz[v]))%mod;
		}
		int tmp=(0ll+s1.query(n)+s2.query(dfn[u])-s0.query(dfn[u])-s1.query(dfn[u],dfn[u]+siz[u]-1))%mod;
		res=(res+(n-siz[u])*1ll*(siz[u]-1)%mod*iv2+n-siz[u]+tmp*1ll*siz[u]+1)%mod;
		ans=(ans+v[i].fi*1ll*res)%mod;
		s1.add(dfn[u],siz[u]);
		s0.add(dfn[u]+1,siz[u]);
		s0.add(dfn[u]+siz[u],(mod-siz[u])%mod);
		for(int j=head[u];j;j=e[j].ne)
		{
			int v=e[j].v;
			if(v==fa[u]) continue;
			s2.add(dfn[v],n-siz[v]);
			s2.add(dfn[v]+siz[v],(mod-(n-siz[v]))%mod);
		}
	}
	write(ans);
	return 0;
}
