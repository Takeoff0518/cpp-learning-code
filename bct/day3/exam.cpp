#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (500005)
#define M (500005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
int a[N];
int num_edge,head[N];
struct E{
	int nxt,to,dis;
}edge[M];
void add(int from,int to){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    head[from]=num_edge;
}
int main(){
	freopen("exam.in","r",stdin);
	freopen("exam.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		add(u,v); add(v,u);
	}
    return 0;
}

