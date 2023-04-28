#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int dis[N][N],n,m,sx,sy;
bool vis[N][N];
const int dx[]={-1,-2,-2,-1,1,2,2,1},
		  dy[]={2,1,-1,-2,2,1,-1,-2};
struct node{
	int x,y;
};
queue<node> q;
void bfs(int x,int y){
	q.push((node){x,y});
	while(!q.empty()){
		int xx=q.front().x,
			yy=q.front().y;
		q.pop();
		for(int i=0;i<8;i++){
			int fx=xx+dx[i],
				fy=yy+dy[i];
			if(fx<1 || fx>n || fy<1 || fy>m || vis[fx][fy]){
				continue;
			}
			vis[fx][fy]=1;
			q.push((node){fx,fy});
			dis[fx][fy]=dis[xx][yy]+1;
		}
	}
}
int main(){
	scanf("%d %d %d %d",&n,&m,&sx,&sy);
	bfs(sx,sy);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(sx==i && sy==j){
				printf("%-5d",0);
			}else if(!vis[i][j]){
				printf("%-5d",-1);
			}else{
				printf("%-5d",dis[i][j]);
			}
		}
		puts("");
	}
    return 0;
}

