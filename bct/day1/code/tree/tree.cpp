#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (500005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (1000000007)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,ans;
int w[N],pre[N];
struct E{
	int nxt,to;
}edge[M];
int head[N],num_edge;
inline void add(int from,int to){
	num_edge++;
	edge[num_edge].nxt=head[from];
	edge[num_edge].to=to;
	head[from]=num_edge;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
		pre[i]=pre[i-1]+w[i];
	}
	for(int i=1,u,v;i<n;i++){
		scanf("%d %d",&u,&v);
		add(u,v); add(v,u);
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			ans+=(pre[j]-pre[i-1])*(j-i+1);
			ans%=mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}

