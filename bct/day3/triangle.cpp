#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n;
int g[N<<1][N<<1];
int ans=-1;
bool vis[N<<1];
void dfs(int loc,int dist){
//	printf("->%d/%d",loc,dist);
	if(loc==n*2){
		ans=max(ans,dist);
//		printf(" done, ans=%d\n",ans);
		return;
	}
	for(int i=2;i<=n*2;i++){
		if(!vis[i] && g[loc][i]!=-1){
			vis[i]=1;
			dfs(i,dist+g[loc][i]);
			vis[i]=0;
		}
	}
//	puts("nxt");
}
//int dis[N<<1],vis[N<<1],cnt[N<<1];
//queue<node>q;
//void func(){
//	memset(dis,-0x3f,sizeof(dis));
//	dis[2]=0,vis[2]=1;
//	cnt[2]++; q.push(2);
//	while(!q.empty()){
//		int p=q.front(); q.pop();
//		vis[p]=0;
////		if(dis[n]==INF) break;
//		if(cnt[p]>n) vis[p]=0;
//		for(int i=2;i<=n;i++)
//	}
//	for(int i=2;i<=n*2;i++){
//		for(int j=2;j<=n*2;j++){
//			for(int k=2;k<=n*2;k++){
//				g[i][j]=max(g[i][j],g[i][k]+g[k][j]);
//			}
//		}
//	}
//	ans=dis[n*2];
//	ans=g[2][n*2];
//}

int main(){
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	scanf("%d",&n);
	memset(g,-1,sizeof(g));
	for(int i=1,a;i<n;i++){
		for(int j=1;j<=i;j++){
			scanf("%d",&a);
			g[i+j][i+j+1]=g[i+j+1][i+j]=a;
		}
	}
	for(int i=1,b;i<n;i++){
		for(int j=1;j<=i;j++){
			scanf("%d",&b);
			g[i+j][i+j+2]=g[i+j+2][i+j]=b;
		}
	}
	for(int i=1,c;i<n;i++){
		for(int j=1;j<=i;j++){
			scanf("%d",&c);
			g[i+j+1][i+j+2]=g[i+j+2][i+j+1]=c;
		}
	}
//	vis[2]=1;
	dfs(2,0);

//	func();
	printf("%d\n",ans);
//	for(int i=1;i<=n*2;i++){
//		for(int j=1;j<=n*2;j++){
//			printf("%d ",g[i][j]);
//		}
//		puts("");
//	}
//	
//	for(int i=1;i<=n*2;i++){
//		printf("%d ",dis[i]);
//	}
//	puts("");
    return 0;
}


