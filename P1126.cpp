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
int n,m,sx,sy,ex,ey,sd;
const int dx[]={0,1,0,-1},
		  dy[]={1,0,-1,0};
char tmp;
bool g[N][N],vis[N][N];
struct node{
	int x,y,d,step;
};
queue<node> q;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
		}
	}
	cin>>sx>>sy>>ex>>ey>>tmp;
	switch(tmp){
		case 'E': st=0; break;
		case 'S': st=1; break;
		case 'W': st=2; break;
		case 'N': st=3; break;
	}
	q.push((node){sx,sy,0,st});
	while(!q.empty()){
		node now=q.front();
		q.pop();
		if(now.x==ex && now.y==ey){
			cout<<now.step<<endl;
			return 0;
		}
		int xx=now.x+dx[now.d],yy=now.y+dy[now.d];
		if(!vis[xx][yy]){
			q.push((node){xx,yy,now.d,now.step+1});
		}
		
	}
	cout<<-1<<endl;
    return 0;
}
//F**k CCF!!!!!
