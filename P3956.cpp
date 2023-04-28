#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
#define red 0
#define yellow 1
const int N=105,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m;
int g[N][N],level[N][N];
const int ddx[4]={1,-1,0,0},ddy[4]={0,0,1,-1};
struct node{
	int x,y,color,cost;
};
queue<node> q;
int main(){
	scanf("%d %d",&m,&n);
	memset(g,-1,sizeof(g));
	memset(level,0x3f,sizeof(level));
	for(int i=1,x,y,c;i<=n;i++){
		scanf("%d %d %d",&x,&y,&c);
		g[x][y]=c;
	}
	//bfs
	int ans=INF;
	q.push((node){1,1,g[1][1],0});
	level[1][1]=0;
	while(!q.empty()){
		int x=q.front().x,
			y=q.front().y,
			c=q.front().color,
			v=q.front().cost;
		if(v>ans){
			q.pop();
			continue;
		}
		if(x==m && y==m){
			ans=min(ans,v);
			q.pop();
			continue;
		}
		for(int i=0;i<4;i++){
			int dx=x+ddx[i],
				dy=y+ddy[i];
			if(dx<1 || dx>m || dy<1 || dy>m) continue;
			int bc=g[x][y],dc=g[dx][dy],mv=level[dx][dy],dv;
			if(dc>=0 && bc>=0){
				dv=v+(dc==bc ? 0 : 1);
				if(mv>dv){
					q.push((node){dx,dy,dc,dv});
					level[dx][dy]=dv;
				}
			}else if(dc<0 && bc>=0){
				if(mv>v+2){
					q.push((node){dx,dy,bc,v+2});
					level[dx][dy]=v+2;
				}
			}else if(dc>=0&&bc<0){
            	dv=v+(c==dc?0:1);
            	if(mv>dv){
                	q.push((node){dx,dy,dc,dv});
            		level[dx][dy]=dv;
            	}
            }
		}
		q.pop();
	}
	if(ans==INF){
		puts("-1");
	}else{
		printf("%d\n",ans);
	}
    return 0;
}

