#include<iostream>
#include<cstdio>
#include<cstring>
#define ull unsigned long long
#define ll long long
#define N 500005
#define INF 0x3f3f3f3f
using namespace std;
struct Edge{
	int nxt,to,dis;
}edge[N];
int num_edge,head[N],dis[N];
bool vis[N];
void add(int from,int to,int dis){
	num_edge++;
	edge[num_edge].nxt=head[from];
	edge[num_edge].to=to;
	edge[num_edge].dis=dis;
	head[from]=num_edge;
}
int n,m,s;
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=n;i++){
		dis[i]=INF,vis[i]=0;
	}
	dis[s]=0;
	for(int i=1;i<=n;i++){
		int min_dis=INF,min_i=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==0 && dis[j]<min_dis){//找到距离起点距离最短的点 
				min_dis=dis[j];
				min_i=j;
			}
			
		}
		if(min_i==0)
			break;
		vis[min_i]=1;
		for(int j=head[min_i];j;j=edge[j].nxt){
			int p=edge[j].to;
			if(vis[p]==0 && dis[p]>dis[min_i]+edge[j].dis){
				dis[p]=dis[min_i]+edge[j].dis;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dis[i]!=INF)
			cout<<dis[i]<<' ';
		else
			cout<<"2147483647 ";
	}
	return 0;
}
