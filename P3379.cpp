#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
const int N=500005,M=1000005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
struct E{
	int nxt,to;
}edge[M];
int head[N],num_edge;
void add(int from,int to){
	num_edge++;
	edge[num_edge].nxt=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}
int depth[N],fa[N][21];
queue<int> q;
int n,m,s;
void bfs(int root){
	memset(depth,0x3f,sizeof(depth));
	depth[0]=0,depth[root]=1;//0���ڱ�
	q.push(root);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=head[t];i;i=edge[i].nxt){
			int j=edge[i].to;
			if(depth[j]>depth[t]+1){//û�ѹ� 
				depth[j]=depth[t]+1;
				q.push(j);
				fa[j][0]=t;
				for(int k=1;k<=20;k++){
					fa[j][k]=fa[fa[j][k-1]][k-1];
				}
			}
		}
	} 
}
int lca(int a,int b){
	if(depth[a]<depth[b]) swap(a,b);
	for (int k=20;k>=0;k--){
		if(depth[fa[a][k]]>=depth[b])
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
	scanf("%d %d %d",&n,&m,&s);
	for(int i=1,a,b;i<=n-1;i++){
		scanf("%d %d",&a,&b);
		add(a,b);add(b,a);
	}
	bfs(s);
	for(int i=1,a,b;i<=m;i++){
		scanf("%d %d",&a,&b);
		printf("%d\n",lca(a,b));
	}
    return 0;
}
//F**k CCF!!!!!

