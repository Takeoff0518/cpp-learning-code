#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#define ull unsigned long long
#define ll long long
#define N 200005
#define INF 0x3f3f3f3f
using namespace std;
int head[N],num_edge;
int dis[N];
bool vis[N];
struct Edge{
	int nxt,to,dis;
}edge[2*N];
void add(int from,int to,int dis){
	num_edge++;
	edge[num_edge].nxt=head[from];
	edge[num_edge].to=to;
	edge[num_edge].dis=dis;
	head[from]=num_edge;
}
int idx,n,q,tot,now=1,ans;
int main(){
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);//˫��ӱ� 
		add(v,u,w);
	}
	for(int i=2;i<=n;i++)
		dis[i]=INF;
	for(int i=head[1];i;i=edge[i].nxt){
		dis[edge[i].to]=min(dis[edge[i].to],edge[i].dis);
	}
	for(int i=1;i<=n-1;i++){
		int minn=INF;
		vis[now]=1;
		
		for(int j=1;j<=n;j++){//ö��ÿһ��û��ʹ�õĵ�,�ҳ���Сֵ��Ϊ�±�
			if(vis[j]==0 && minn>dis[j]){
				minn=dis[j];
				now=j;
			}
		}
		if(minn==INF){
			cout<<"orz"<<endl; 
			return 0;
		}
		ans+=minn;
		for(int j=head[now];j;j=edge[j].nxt){//ö��now���������ߣ�����dist����
			int v=edge[j].to;
			if(dis[v]>edge[j].dis && vis[v]==0){
				dis[v]=edge[j].dis;
			} 
		}
	}
	cout<<ans<<endl;
	return 0;
}
