#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
const int N=1005,M=1e4;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m;
int s,t;
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
int dis[N][N],p[N],nxt[N][N];
double f[N][N];//不会炸吧
bool vis[N],vis2[N][N];
void spfa(int s){
    queue<int> q;
    //memset(dis[s],0x3f,sizeof(dis[s]));
    memset(vis,0,sizeof(vis));
    dis[s][s]=0;
    q.push(s);
    while(!q.empty()){
        //puts("awa");
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=edge[i].nxt){
            int p=edge[i].to;
            if(dis[s][u]+1<dis[s][p]){
                dis[s][p]=dis[s][u]+1;
                if(!vis[p]){
                    vis[p]=1;
                    q.push(p);
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d ",dis[s][i]);
    // }
    // puts("");
}
double dfs(int u,int v){
    //puts("awa");
    if(vis2[u][v]){
        return f[u][v];//记忆化搜索
    }
    if(u==v){
        return 0.0;
    }
    int fst=nxt[u][v],sec=nxt[nxt[u][v]][v];
    if(fst==v || sec==v){
        return 1.0;
    }
    f[u][v]=1.0;
    for(int i=head[v];i;i=edge[i].nxt){
        int j=edge[i].to;
        f[u][v]+=1.0*dfs(sec,j)/(p[v]+1);
    }
    f[u][v]+=1.0*dfs(sec,v)/(p[v]+1);
    vis2[u][v]=1;
    return f[u][v];
}
int main(){
    memset(nxt,0x3f,sizeof(nxt));
    memset(dis,0x3f,sizeof(dis));
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(int i=1,u,v;i<=m;i++){
        scanf("%d %d",&u,&v);
        add(u,v);add(v,u);
        p[u]++,p[v]++;
    }
    
    for(int i=1;i<=n;i++){
        spfa(i);
    }
    for(int i=1;i<=n;i++){
		for(int h=head[i];h;h=edge[h].nxt){
			int p=edge[h].to;
			for(int j=1;j<=n;j++){
				if(dis[i][j]-1==dis[p][j]){
					nxt[i][j]=min(nxt[i][j],p);
				}
            }
		}
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         printf("%d ",dis[i][j]);
    //     }
    //     puts("");
    // }
    double anss=dfs(s,t);
    //cout<<anss<<endl;
    printf("%.3lf\n",anss);
    return 0;
}