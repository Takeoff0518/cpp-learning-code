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
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define SZ(x) ((int)(x.size()))
#define INF 0x3f3f3f3f

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

const int N=1e6+5;
int n,K;
char s[N];

struct Trie
{
	int cnt,tg[N],siz[N],ch[N][26];
	void insert()
	{
		int u=1;
		int len=strlen(s+1);
		for(int i=1;i<=len;++i)
		{
			siz[u]++;
			if(!ch[u][s[i]-'a'])
				ch[u][s[i]-'a']=++cnt;
			u=ch[u][s[i]-'a'];
		}
		tg[u]++;siz[u]++;
	}
}tr;

signed main()
{ 
	freopen("name.in","r",stdin);
	freopen("name.out","w",stdout);
	n=read();K=read();
	tr.cnt++;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		tr.insert();
	}
	int u=1;
	while(1)
	{
		int nm=tr.tg[u];
		for(int i=0;i<26;++i)
			if(tr.siz[tr.ch[u][i]]) nm++;
		if(nm>=K)
		{
			if(u==1)
				puts("EMPTY");
			else puts("");
			return 0;
		}
		for(int i=0;i<26;++i)
			if(tr.siz[tr.ch[u][i]])
			{
				nm+=tr.siz[tr.ch[u][i]]-1;
				if(nm>=K)
				{
					K-=nm-tr.siz[tr.ch[u][i]];
					u=tr.ch[u][i];putchar(i+'a');
					break;
				}
			}
	}
	return 0;
}
