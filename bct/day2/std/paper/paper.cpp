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
int n,m,p[N];
char s1[N],s2[N];

void solve()
{
	for(int i=n;i>=0;--i)
	{
		s1[2*i+2]=s2[i];
		s1[2*i+1]='#';
	}
	s1[0]='$';
	int mxr=0,mid=0;
	for(int i=0;i<=2*n+1;++i)
	{
		if(mxr>i) p[i]=min(mxr-i,p[2*mid-i]);
		while(s1[i-p[i]]==s1[i+p[i]]) ++p[i];
		if(i+p[i]>mxr) mxr=i+p[i],mid=i;
	}
}

signed main()
{
	freopen("paper.in","r",stdin);
	freopen("paper.out","w",stdout);
	n=read();m=read();
	scanf("%s",s2);
	solve();
	for(int i=1;i<=m;++i)
	{
		int x=read()-1,y=read()-1;
		int mid =x+((y-x)>>1);
		if((y-x+1)%2==1&&p[mid*2+2]>=y-x+2) puts("TIE");
		else if((y-x+1)%2==0&&p[mid*2+3]>=y-x+2) puts("TIE");
		else if((y-x+1)%2==1) puts("PP");
		else puts("GG");
	}
}
