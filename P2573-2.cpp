#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
#define maxn 1000100
int read() {
	int x = 0, w = 1;
	char ch = 0;
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		ch = getchar();               
	}
	while (ch >= '0' && ch <= '9') {  
		x = x * 10 + (ch - '0');  
		ch = getchar();
	}
	return x * w;  
}
void write(int x)
{
	if(x<0){x=-x;putchar('-');}
	if(x>9)  write(x/10);
	putchar(x%10+'0');
}
int n,m;
bool vis[maxn];
long long ans_cnt=0,ans_tot=0;
struct node{
	int num,h;
}nodee[100010];
struct edge{
	int v,w;
};
struct edgee{
	int u,v,w;
};
vector < edge >  e[100010];
vector < edgee >  ee;

bool cmp(edgee x,edgee y)
{
	if(nodee[x.v].h!=nodee[y.v].h)
	{
		return nodee[x.v].h>nodee[y.v].h;
	}
	return x.w<y.w;
}

int fa[100010];
void mekeset(int n)
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
}
int find(int x)
{
	if(fa[x]!=x)
	{
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
void mergeset(int x,int y)
{
	x=find(x);
	y=find(y);
	fa[x]=y;
}

void dfs(int now)
{
	vis[now]=true;
	ans_cnt++;
	for(int i=0;i<e[now].size();i++)
	{
		ee.push_back((edgee){now,e[now][i].v,e[now][i].w});
		if(!vis[e[now][i].v])
		{
			dfs(e[now][i].v);
		}
	}
	
}

int main()
{
	n=read(),m=read();
	mekeset(n);
	for(int i=1;i<=n;i++)
	{
		nodee[i].h=read();
		nodee[i].num=i;
	}
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		if(nodee[u].h>=nodee[v].h)
		{
			e[u].push_back((edge){v,w});
		}
		else if(nodee[u].h<=nodee[v].h){
			e[v].push_back((edge){u,w});
		}
	}
	dfs(1);
	printf("%lld",ans_cnt);
	sort(ee.begin(),ee.end(),cmp);
	long long cnt=0;
	for(int i=0;i<ee.size();i++)
	{
		if(find(ee[i].u)!=find(ee[i].v))
		{
			cnt++;
			ans_tot+=ee[i].w;
			mergeset(ee[i].u,ee[i].v);
//			if(cnt==ans_cnt-1)
//			{
//				printf(" %lld",ans_tot);
//				return 0;
//			}
		}
	}
	printf(" %lld",ans_tot);
	return 0;
}