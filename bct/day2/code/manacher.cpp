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

const int N=3e7+5;
int n,m,len[N];
char S[N],s[N];

signed main()
{
	scanf("%s",S+1);
	n=strlen(S+1);
	s[++m]='#';
	for(int i=1;i<=n;++i)
	{
		s[++m]=S[i];
		s[++m]='#';
	}
	int ps=0,lim=0;
	for(int i=1;i<=m;++i)
	{
		if(ps<=i&&i<=lim)
			len[i]=min(len[ps*2-i],lim-i+1);
		while(i-len[i]>=1&&s[i-len[i]]==s[i+len[i]]) ++len[i];
		if(i+len[i]-1>lim) lim=i+len[i]-1,ps=i;
	}
	int ans=0;
	for(int i=1;i<=m;++i)
		ans=max(ans,len[i]-1);
	write(ans);
	return 0;
}
