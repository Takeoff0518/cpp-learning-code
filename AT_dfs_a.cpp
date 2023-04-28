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
struct node{
	int x,y;
};
queue<node> q;
char t[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
int sx,sy,ex,ey;
bool bfs(int x,int y){
	q.push((node){x,y});
	while(!q.empty()){
		int xx=q.front().x;
		int yy=q.front().y;
		q.pop();
		if(xx==ex && yy==ey){
			return 1;
		}
		for(int i=0;i<4;i++){
			int fx=xx+dx[i],
				fy=yy+dy[i];
			if(t[fx][fy]!='#'){
				q.push((node){fx,fy});
				t[fx][fy]='#';
			}
		}
	}
	return 0;
}
int main(){
	cin>>n>>m;
	memset(t,'#',sizeof(t));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>t[i][j];
			if(t[i][j]=='s'){
				sx=i,sy=j;
			}
			if(t[i][j]=='g'){
				ex=i,ey=j;
			}
		}
	}
	if(bfs(sx,sy)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
    return 0;
}

