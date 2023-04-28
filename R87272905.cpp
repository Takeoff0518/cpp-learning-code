#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x<y?y:x;}
const int MAXN = 5e5+10;
const int INF = 2147483647;
int n,m,s,d[MAXN],head[MAXN],tot;
bool vis[MAXN];
struct edge{int to,next,weight;}a[MAXN*6];
struct node{
	int dis,pos;
	bool operator <(const node&x)const{
		return x.dis<dis;
	}
};
std::priority_queue<node> q;
void add(int x,int y,int z){
	a[++tot].to=y;
	a[tot].next=head[x];
	head[x]=tot;
	a[tot].weight=z;
}
// void Dij(int s){
// 	memset(vis,0,sizeof(vis));
	
// }
int main(){
	scanf("%d%d%d",&n,&m,&s);
	memset(d,0x3f,sizeof(d));
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	for(int i=1;i<=n;i++) d[i]=INF;
	d[s]=0;
	q.push((node){0,s});
	while(q.size()){
		node tmp=q.top();
		q.pop();
		int x=tmp.pos;
		if(vis[x]) continue;
		vis[x]=true;
		for(int i=head[x];i;i=a[i].next){
			int y=a[i].to;
			if(d[y]>d[x]+a[i].weight){
				d[y]=d[x]+a[i].weight;
				if(!vis[y])
					q.push((node){d[y],y});
			}
		}
	}
	for(int i=1;i<=n;i++){
        if(d[i]!=d[0])
		    printf("%d ",d[i]);
        else
            printf("%d ",INF);
	}
	return 0;
}