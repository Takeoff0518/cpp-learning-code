#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#define N (2505)
#define M (20005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<ll,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,k;
ll s[N];
int dis[N][N];
struct E{
    int nxt,to;
}edge[M];
int head[N],num_edge;
void add(int from,int to){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    head[from]=num_edge;
}
bool vis[N];
void bfs(int s){
    queue<int> q;
    memset(vis,0,sizeof(vis));
    dis[s][s]=0;
    q.push(s);
    while(!q.empty()){
        int t=q.front(); q.pop();
        if(vis[t]) continue;
        vis[t]=1;
        for(int i=head[t];i;i=edge[i].nxt){
            int j=edge[i].to;
            if(dis[s][j]>dis[s][t]+1){
                dis[s][j]=dis[s][t]+1;
                if(!vis[j]) q.push(j);
            }
        }
    }
}
set<PII> bs[N];
ll ans=0;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=2;i<=n;i++) scanf("%lld",&s[i]);
    for(int i=1,u,v;i<=m;i++){
        scanf("%d %d",&u,&v);
        add(u,v); add(v,u); 
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)	bfs(i);
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i==j) continue;
			if(dis[i][j]<=k+1 && dis[1][j]<=k+1){
				bs[i].insert({s[j],j});
			}
			if(bs[i].size()>3){
				bs[i].erase(bs[i].begin());
			}
		}
	}
	for(int b=2;b<=n;b++){
		for(int c=2;c<=n;c++){
			if(dis[b][c]>k+1 || b==c) continue;
			for(PII a:bs[b]){
				if(a.second==b || a.second==c) continue;
				for(PII d:bs[c]){
					if(d.second==b || d.second==c || d.second==a.second)
						continue;
					ans=max(ans,s[b]+s[c]+s[a.second]+s[d.second]);
				}
			}
		}
	}
	printf("%lld\n",ans);
    return 0;
}
