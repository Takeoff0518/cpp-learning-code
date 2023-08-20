#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (100005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int t;
int n,m,k;
char bel[N];
//struct T{
//	int nxt,to;
//}e[N<<1];
//int head[N],num_edge;
//void add(int from,int to){
//	
//}
int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false); //endl!!!!!
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>bel+1;
		int u,v;
		for(int i=1,u,v;i<=m;i++){
			cin>>u>>v;
//			add(u,v); add(v,u);	
		}
		// m-> n-1
		int round=m-(n-1);
		if(bel[round%k+1]=='G')
			cout<<'P'<<endl;
		else cout<<'G'<<endl;
	}
    return 0;
}


