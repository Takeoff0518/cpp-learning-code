#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=505,M=50005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m,e;
int head[N],num_edge;
struct E{
	int nxt,to;
}edge[M];
void add(int from,int to){
	num_edge++;
	edge[num_edge].nxt=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}
bool st[N];
int match[N],ans;
bool find(int x){
	for(int i=head[x];i;i=edge[i].nxt){
		int j=edge[i].to;
		if(!st[j]){
			st[j]=1;
			if(!match[j] || find(match[j])){
				match[j]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d %d %d",&n,&m,&e);
	for(int i=1,u,v;i<=e;i++){
		scanf("%d %d",&u,&v);
		add(u,v);
	}
	for(int i=1;i<=n;i++){
		memset(st,0,sizeof(st));
		if(find(i)){
			ans++;
		}
	}
	printf("%d\n",ans);
    return 0;
}
//F**k CCF!!!!!

