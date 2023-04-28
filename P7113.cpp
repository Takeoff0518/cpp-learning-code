#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (100005)
#define M (500005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define lint __int128
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
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
lint gcd(lint a,lint b){
	while(a^=b^=a^=b%=a);
	return b;
} 
//int fn[N],fn_cnt;
int out[N],in[N];
queue<int> q;
lint P[N],Q[N];
void wt(lint x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wt(x/10);
	putchar(x%10+'0');
}
void dag(){
	for(int i=1;i<=n;i++){
		Q[i]=1;
		if(in[i]==0){
			q.push(i);
			P[i]=1;
		}
	}
	while(!q.empty()){
		int t=q.front(); q.pop();
		lint t_out_p=P[t],t_out_q=out[t]*Q[t];//分母与分子 
		for(int i=head[t];i;i=edge[i].nxt){
			int j=edge[i].to; in[j]--;
			P[j]=Q[j]*t_out_p+P[j]*t_out_q;
			Q[j]*=t_out_q;
			lint t_gcd=gcd(P[j],Q[j]);
			P[j]/=t_gcd,Q[j]/=t_gcd;
			if(in[j]==0) q.push(j);
		}
	}
}
int main(){
//	freopen("water/water7.in","r",stdin);
//	freopen("water/out.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&out[i]);
		for(int j=1,v;j<=out[i];j++){
			scanf("%d",&v);
			in[v]++;
			add(i,v);
		}
	}
	dag();
	for(int i=1;i<=n;i++){
		if(out[i]==0){
			lint tgcd=gcd(P[i],Q[i]);
			wt(P[i]/tgcd); putchar(' '); wt(Q[i]/tgcd); putchar('\n'); 
//			printf("%lld %lld\n",P[i]/tgcd,Q[i]/tgcd);
		}
	}
    return 0;
}
//F**k CCF!!!!!

