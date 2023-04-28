#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=10005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m,sx,sy;
bool g[N][N];
int pre[N][N];
inline int ask(int x1,int y1,int x2,int y2){
	if(x1>x2) swap(x1,x2);
	if(y1>y2) swap(y1,y2); 
	return pre[x2][y2]+pre[x1-1][y1-1]-pre[x1-1][y2]-pre[x2][y1-1];
}
inline void check(int x1,int y1,int x2,int y2){
	if(x1>x2) swap(x1,x2);
	if(y1>y2) swap(y1,y2); 
	if(!ask(x1,y1,x1,y2) &&
	   !ask(x1,y2,x2,y2) &&
	   !ask(x2,y2,x2,y1) &&
	   !ask(x1,y1,x2,y1)
	){
	   	//printf("%d %d %d %d\n",x1,y1,x2,y2);
	   	puts("Yes");
	   	exit(0);
	   }
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;
			cin>>c;
			if(c=='#')
				g[i][j]=1;
			if(c=='S')
				sx=i,sy=j;
			
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+g[i][j];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			printf("%d ",pre[i][j]);
//		}
//		puts("");
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i!=sx && j!=sy){
				check(sx,sy,i,j);
			}
		}
	}
	puts("No");
    return 0;
}
//F**k CCF!!!!!

