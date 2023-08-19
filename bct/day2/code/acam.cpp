#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define lowbit(x) (x&(-x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define max Max
#define min Min
#define abs Abs

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
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=1e6+5;
int n,en[N],tr[N][27],fail[N],cnt;
char s[N];

inline void insert(char *x);
inline void getfail();
inline int getans(char *x);

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		insert(s);
	}
	getfail();
	scanf("%s",s+1);
	printf("%lld\n",getans(s));
	return 0;
}

inline void insert(char *x)
{
	int u=0,l=strlen(x+1);
	for(int i=1;i<=l;++i)
	{
		if(!tr[u][x[i]-'a']) tr[u][x[i]-'a']=++cnt;
		u=tr[u][x[i]-'a'];
	}
	en[u]++;
}

inline void getfail()
{
	queue<int> qu;
	for(int i=0;i<26;++i) if(tr[0][i]) qu.push(tr[0][i]);
	while(!qu.empty())
	{
		int u=qu.front();
		qu.pop();
		for(int i=0;i<26;++i)
			if(tr[u][i]) fail[tr[u][i]]=tr[fail[u]][i],qu.push(tr[u][i]);
			else tr[u][i]=tr[fail[u]][i];
	}
}

inline int getans(char *x)
{
	int u=0,res=0,l=strlen(x+1);
	for(int i=1;i<=l;++i)
	{
		u=tr[u][x[i]-'a'];
		for(int j=u;j&&en[j]!=-1;j=fail[j])
			res+=en[j],en[j]=-1;
	}
	return res;
}
