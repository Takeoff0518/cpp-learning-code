#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (50005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
struct E{
	int nxt,to,dis;
}e[N];
int h[N],idx;
void add(int from,int to,int dis){
	e[++idx].nxt=h[from];
	e[idx].to=to;
	e[idx].dis=dis;
	h[from]=idx;
}
queue<int> q;
int cnt[N],dis[N];
bool vis[N];
bool spfa(int s){
	queue<int>().swap(q);
	memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
	dis[s]=0; vis[s]=1; cnt[s]++;
	q.push(s);
	while(!q.empty()){
		int t=q.front(); q.pop();
		vis[t]=0;
		for(int i=h[t];i;i=e[i].nxt){
            int j=e[i].to;
            if(dis[j]>dis[t]+e[i].dis){
                dis[j]=dis[t]+e[i].dis;
                if(vis[j]==0){
                    vis[j]=1;
                    q.push(j); cnt[j]++;
                }
                if(cnt[j]>n) return 1;
            }
        }
	}
	return 0;
}
int main(){
	int t; scanf("%d",&t);
 	while(t--){
        scanf("%d %d",&n,&m);
        idx=0;
        memset(h,0,sizeof(h));
        for(int i=1,u,v,w;i<=m;i++){
            scanf("%d %d %d",&u,&v,&w);
            if(w>=0){
                add(u,v,w); add(v,u,w);
            }else add(u,v,w);
        }
        if(spfa(1)) puts("YES");
        else puts("NO");
    }
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

