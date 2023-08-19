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

const int N=3e5+5;
int n,cnt,dfn[N],low[N],f[N],rid[N];
char s[N];

struct Edge
{
	int v,w,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v,int w)
{
	e[++tot]=(Edge){v,w,head[u]};
	head[u]=tot;
}

void dfs(int u,int fa)
{
    dfn[u]=++cnt;rid[cnt]=u;
    for(int i=head[u];i;i=e[i].ne)
    {
    	int v=e[i].v;
    	if(v==fa) continue;
    	dfs(v,u);
	}
    low[u]=cnt;
}

signed main()
{
	freopen("trie.in","r",stdin);
	freopen("trie.out","w",stdout);
	n=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		scanf("%s",s+1);
		add(u,v,s[1]-'a');
		add(v,u,s[1]-'a');
	}
    cnt=0;dfs(1,0);
    vector<int> ans;
    for(int u=1;u<=n;++u)
	{
        vector<int> vec[26];
        for(int i=head[u];i;i=e[i].ne)
       		vec[e[i].w].push_back(e[i].v);
        int t=-1;
        for(int i=0;i<26;++i)
		{
            if(vec[i].size()>2)
			{
				printf("0\n");
				return 0;
			}
            else if(vec[i].size()==2)
			{
                if(t>=0)
				{
					printf("0\n");
					return 0;
				}
                t=i;
            }
        }
        if(t==-1) continue;
        int x=vec[t][0],y=vec[t][1];
        if(dfn[x]>dfn[y]) swap(x,y);
        if(dfn[u]<dfn[x]&&dfn[u]<dfn[y])
		{
            f[1]++;f[n+1]--;
            f[dfn[x]]--;f[low[x]+1]++;
            f[dfn[y]]--;f[low[y]+1]++;
        }
		else
		{
            f[dfn[u]]++;f[low[u]+1]--;
            f[dfn[y]]--;f[low[y]+1]++;
        }
    }
    for (int i=1;i<=n;++i)
	{
        f[i]+=f[i-1];
        if(f[i]==0)
			ans.push_back(rid[i]);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",SZ(ans));
    for(int i=0;i<SZ(ans);++i)
    	write(ans[i]),putchar(' ');
    return 0;
}
