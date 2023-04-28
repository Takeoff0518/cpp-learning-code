#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
const int N=1005,M=20005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
struct E{
	int nxt,to,v;
}edge1[M],edge2[M];
int head1[N],head2[N];
int num_edge1,num_edge2;
void add1(int from,int to,int dis){
	num_edge1++;
	edge1[num_edge1].nxt=head1[from];
	edge1[num_edge1].to=to;
	edge1[num_edge1].v=dis;
	head1[from]=num_edge1;
}
void add2(int from,int to,int dis){
	num_edge2++;
	edge2[num_edge2].nxt=head1[from];
	edge2[num_edge2].to=to;
	edge2[num_edge2].v=dis;
	head2[from]=num_edge2;
}
struct node{
	int pos,dis;
	inline bool operator < (const node &x) const{
		return x.dis<dis;
	}
};
int n,m,n,dis[N];
bool vis[N];
void djikstra(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<node> q;
	q.push((node){s,0});
	while(!q.empty()){
		int min_i=q.top().pos;
		q.pop();
		if(vis[min_i]){
			continue;
		}
		for(int i=head2[min_i];i;i=edge2[i].nxt){
			int p=edge2[i].to;
			if(dis[p]>dis[min_i]+edge2[i].to){
				dis[p]=dis[min_i]+edge2[i].to;
				if(!vis[p]){
					q.push((node){dis[p],p});
				}
			}
		}
	}
}
int a_star(int ret){
	priority_queue<node,vector<node>,less<node> >q;
	q.push((node){n,0});
	while(!q.empty()){
		node pp=q.top();
		q.pop();
		if(pp.pos==1){
			printf("%d\n",pp.dis);
			if((--ret)==0){
				return 0;
			}
		}
		int min_i=pp.pos;
		for(int i=head1[i];i;i=edge1[i].nxt){
			int p=edge1[i].to;
			q.push((node){p,pp.dis+edge1[i].v});
		}
	}
	return ret;
} 
int main(){
	scanf("%d %d %d",&n,&m,&n);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		add1(u,v,w);add2(v,u,w);
	}
	djikstra(n);//n�ŵ��ܷ���ͼ
	a_star(n);
	while(n--){
		puts("-1");
	}
    return 0;
}

