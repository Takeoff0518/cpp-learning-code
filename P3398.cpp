#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
const int N=100005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
struct E{
    int nxt,to,v;
}edge[M];
int head[N],num_edge;
void add(int from,int to,int dis){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    edge[num_edge].v=dis;
    head[from]=num_edge;
}
int dep[N],fa[N][30];
queue<int> q;
void bfs(int root){
	memset(dep,0x3f,sizeof(dep));
	dep[0]=[0],dep[root]=1;
	q.push(root);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=head[t];i;i=edge[i].nxt){
			int j=edge[i].to;
			if(dep[j]>dep[t]+1){
				dep[j]=dep[t]+1;
				q.push(j);
				fa[j][0]=t;
				for(int k=1;k<=30;k++)
					fa[j][k]=fa[fa[j][k-1]][k-1];
			}
		}
	}
}
int lca(int a,int b){
	if(dep[a]>dep[b]) swap(a,b);
	for(int k=20;k>=0;k--){
		if(dep[fa[a][k]]>=dep[b])
			a=fa[a][k];
	}
	if(a==b) return a;
	for(int k=20;k>=0;k--){
		if(fa[a][k]!=fa[b][k])
			a=fa[a][k],b=fa[b][k];
	}
	return fa[a][0];
}
int main(){

    return 0;
}
//F**k CCF!!!!!

