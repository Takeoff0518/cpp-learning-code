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
const int dx[12]={1,1,2,2,2,2,-1,-1,-2,-2,-2,-2},
		  dy[12]={-2,2,-2,-1,1,2,-2,2,-1,1,-2,2};
int dis[N][N];
bool vis[N][N];
int x1,x2,y1,y2;
struct node{
	int x,y;
};
queue<node> q;
void dfs(int x,int y){
	q.push((node){x,y});
	while(!q.empty()){
		int xx=q.front().x,
			yy=q.front().y;
		q.pop();
		for(int i=0;i<12;i++){
			int fx=xx+dx[i],
				fy=yy+dy[i];
			if(fx<1 || fx>20 || fy<1 || fy>20 || vis[fx][fy]){
				continue;
			}
			vis[fx][fy]=1;
			dis[fx][fy]=dis[xx][yy]+1;
			q.push((node){fx,fy});
		}
	}
}
int main(){
	cin>>x1>>y1>>x2>>y2;
	dfs(1,1);
	cout<<dis[x1][y1]<<endl<<dis[x2][y2];
    return 0;
}

