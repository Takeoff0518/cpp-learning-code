#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (7)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int t,ans,maxdep;
int now[N][N];
const int goal[N][N]={
	{0,0,0,0,0,0},
	{0,1,1,1,1,1},
    {0,0,1,1,1,1},
    {0,0,0,2,1,1},
    {0,0,0,0,0,1},
    {0,0,0,0,0,0}
},
dx[]={0,1,1,-1,-1,2,2,-2,-2},
dy[]={0,2,-2,2,-2,1,-1,1,-1};
inline int check(){
	int cnt=0;
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			if(now[i][j]!=goal[i][j]) cnt++;
		}
	}
	return cnt;
}
bool f=0;
void dfs(int dep,int x,int y){
	if(dep==maxdep){
		if(!check()) f=1;
		return;	
	}
	for(int i=1;i<=8;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<1 || xx>5 || yy<1 || yy>5) continue;
		swap(now[x][y],now[xx][yy]);
		int now_val=check();
		if(now_val+dep<=maxdep)
			dfs(dep+1,xx,yy);
		swap(now[x][y],now[xx][yy]);
	}
}
int sx,sy;
int main(){
	ios::sync_with_stdio();
	cin>>t;
	while(t--){
		f=0; 
		for(int i=1;i<=5;i++){
			for(int j=1;j<=5;j++){
				char c;
				cin>>c;
				if(c=='0') now[i][j]=0;
				else if(c=='1') now[i][j]=1;
				else now[i][j]=2,sx=i,sy=j;
			}
		}
		if(!check()) cout<<0<<endl;
		else{
			for(int i=1;i<=15;i++){
				maxdep=i;
				dfs(0,sx,sy);
				if(f){
					cout<<maxdep<<endl;
					goto nxt;
				}
			}
			cout<<-1<<endl;
		}
		nxt:;
	}
    return 0;
}
//F**k CCF!!!!!

