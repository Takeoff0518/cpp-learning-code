#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
int num_edge,n,m,s,t;
int head[1005],p[1005];
int dis[1005][1005],nxt[1005][1005];
bool vis[1005],vis2[1005][1005];
double f[1005][1005];
struct EDGE{
	int to,nxt;
}edge[2005];
#define INF 0x3f3f3f3f

void add(int from,int to)
{
	num_edge++;
	edge[num_edge].to=to;
	edge[num_edge].nxt=head[from];
	head[from]=num_edge;
}

queue < int > q;
void SPFA(int s)
{   
    memset(vis,0,sizeof(vis));
	dis[s][s]=0;
	q.push(s);
	while (!q.empty())
	{
		int u=q.front();q.pop();
		vis[u]=false;
		for (int h=head[u];h;h=edge[h].nxt)
		{
			int v=edge[h].to;
			if (dis[s][u]+1<dis[s][v])
			{
				dis[s][v]=dis[s][u]+1;
				if (!vis[v])
				{
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
}
double dfs(int u,int v)
{
	if (vis2[u][v]) 
        return f[u][v];
	if (u==v) 
        return 0;
	int fst=nxt[u][v];
	int sec=nxt[fst][v];
	if (fst==v||sec==v) 
        return 1;
	f[u][v]=1;
	for (int i=head[v];i;i=edge[i].nxt)
	{
		int j=edge[i].to;
		f[u][v]+=dfs(sec,j)/(p[v]+1);
	}
	f[u][v]+=dfs(sec,v)/(p[v]+1);
	vis2[u][v]=true;
	return f[u][v];
}
int main()
{
    memset(nxt,0x3f,sizeof(nxt));
    memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d%d",&n,&m,&s,&t);
	//memset(head,-1,sizeof head);
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
		p[a]++;p[b]++;
	}
	for (int i=1;i<=n;i++)
	{
		SPFA(i);
	}
	for (int i=1;i<=n;i++)
		for (int h=head[i];h;h=edge[h].nxt)
		{
			int p=edge[h].to;
			for (int j=1;j<=n;j++)
				if (dis[i][j]-1==dis[p][j])
				{
					nxt[i][j]=min(nxt[i][j],p);
				}
		}
	// for (int i=1;i<=n;i++)
	// {
	// 	for (int j=1;j<=n;j++)
	// 		printf("%d ", nxt[i][j]);
	// 	printf("\n");
	// }
	printf("%.3lf",dfs(s,t));
	return 0;
} 
