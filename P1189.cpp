#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
//#define dong 0
//#define xi 1
//#define nan 2
//#define bei 3
const int N=55,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m,t,sx,sy,a[M];
char g[N][N];
bool f[M][N][N];
int dx[]={0,0,-1,1},
	dy[]={-1,1,0,0};
void dfs(int dep,int x,int y){
	//cout<<"goto"<<dep<<' '<<x<<' '<<y<<endl;
	if(f[dep][x][y]){
		return;
	}
	f[dep][x][y]=1;
	if(dep==0){
		return;
	}
	while(1){
		x+=dx[a[dep]],y+=dy[a[dep]];
		if(g[x][y]=='X'){
			break;
		}
		dfs(dep-1,x,y);
	}
	
}
int main(){
    cin>>n>>m;
    memset(g,'X',sizeof(g));
    memset(f,false,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
			if(g[i][j]=='*'){
				sx=i,sy=j;
			}
		}
	}
	cin>>t;
	for(int i=t;i>=1;i--){
		char opt[10];
		cin>>opt;
		if(opt[0]=='N'){
			a[i]=2;
		}else if(opt[0]=='S'){
			a[i]=3;
		}else if(opt[0]=='W'){
			a[i]=0;
		}else if(opt[0]=='E'){
			a[i]=1;
		}
	}
	dfs(t,sx,sy);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<f[0][i][j];
//		} 
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[0][i][j]){
				cout<<'*';
			}else if(g[i][j]!='X'){
				cout<<'.';
			}else{
				cout<<'X';
			}
		}
		cout<<endl;
	}
    return 0;
}
