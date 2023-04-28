#include<bits/stdc++.h>
using namespace std;

const int N=100100;
const int maxm=500500;

int nxt[maxm*42],w[maxm*42],to[maxm*42],head[N*42],num_edge=0;

void add(int from,int v,int cost)
{
	num_edge++;
	nxt[num_edge]=head[from];
	head[from]=num_edge;
	to[num_edge]=v;
	w[num_edge]=cost;
}

struct node
{
	int u,dis;
	bool operator < (const node x) const
	{
		return dis>x.dis;
	}
};

priority_queue<node> q;
int dist[N*21];

void dij(int s)
{
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	q.push((node){s,0});
	while (!q.empty())
	{
		node fr=q.top();q.pop();
		int u=fr.u,dis=fr.dis;
		if (dis!=dist[u]) continue;
		for (int v=head[u];v;v=nxt[v])
			if (dist[to[v]]>dist[u]+w[v])
			{
				dist[to[v]]=dist[u]+w[v];
				q.push((node){to[v],dist[to[v]]});
			}
	}
}
int n,m,n;
int ans=0x3f3f3f3f;
int main()
{
	cin>>n>>m>>n;
	for (int i=1;i<=m;i++){
		int u,v,cost;
		cin>>u>>v>>cost;
		add(u,v,cost);add(v,u,cost);
		for (int j=1;j<=n;j++)
		{
			add(n*j+u,n*j+v,cost);add(n*j+v,n*j+u,cost);
			add(n*(j-1)+u,n*j+v,0);add(n*(j-1)+v,n*j+u,0);
		}
	}
	dij(1);
	
	for (int i=0;i<=n;i++){
		ans=min(ans,dist[i*n+n]);
	}
	cout<<ans;
	return 0;
}
