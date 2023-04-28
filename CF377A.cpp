#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=505,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m,n;
const int dx[]={0,0,1,-1},
		  dy[]={1,-1,0,0};
char g[N][N];
void dfs(int x,int y){
	if(n<=0){
		return;
	}
	g[x][y]='.',n--;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>=1 && xx<=n && yy>=1 && yy<=m && g[xx][yy]=='X' && n){
			dfs(xx,yy);
		}
	}
}
int main(){
	cin>>n>>m>>n;
	n=-n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
			if(g[i][j]=='.'){
				n++,g[i][j]='X';
			}
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]=='X'){
				dfs(i,j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<g[i][j];
		}
		cout<<endl;
	}
    return 0;
}

