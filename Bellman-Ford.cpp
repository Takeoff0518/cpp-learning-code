#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define PII pair<int,int>
const int N=150005,M=150005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
struct E{
	int u,v,w;
}s[M];
int n,m,dis[N];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		s[i]=(E){u,v,w};
	}
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int u=s[j].u,v=s[j].v,w=s[j].w;
			if(dis[v]>dis[u]+w)
				dis[v]=dis[u]+w;
		}
	}
	if(dis[n]==INF) printf("-1\n");
	else printf("%d\n",dis[n]);
    return 0;
}
//F**k CCF!!!!!

