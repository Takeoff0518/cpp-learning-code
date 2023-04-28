#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int f[N][N],p[N],c[N];
int dis[N][N];
int n,m,C,T;
int ans=INF;
bool vis[N];
void dfs(int dint,int now,int energy,int money){
    if(now==dint){
        ans=min(ans,money);
    }
    if(energy<=0){
        return;
    }
}
int main(){
    memset(f,0x3f,sizeof(f));
    memset(dis,0x3f,sizeof(dis));
    scanf("%d %d %d %d",&n,&m,&C,&T);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&p[i],&c[i]);
    }
    for(int i=1,u,v,w;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        f[u][v]=min(f[u][v],w);
    }
    for(int i=1,u,v,d;i<=T;i++){
        scanf("%d %d %d",&u,&v,&d);
    }
    return 0;
}