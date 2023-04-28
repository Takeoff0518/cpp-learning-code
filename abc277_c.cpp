#include<iostream>
#include<cstdio>
#include<map>
const int N=400005,M=1005;
using namespace std;
struct E{
    int nxt,to;
}edge[N];
map<int,int> head;
int num_edge;
void add(int from,int to){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    head[from]=num_edge;
}//链式前向星 
int n,ans=1;
map<int,bool> vis;
void dfs(int x){
	ans=max(ans,x);//记录答案 
	for(int i=head[x];i;i=edge[i].nxt){
		int j=edge[i].to;
		if(!vis[j]){ vis[j]=1; dfs(j);}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,a,b;i<=n;i++){
		scanf("%d %d",&a,&b);
		add(a,b);add(b,a);
	}
	dfs(1);
	printf("%d\n",ans);
    return 0;
}
//F**k CCF!!!!!

