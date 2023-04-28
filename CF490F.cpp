#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define INF 0x3f3f3f3f
#define N 6005
#define ll long long
using namespace std;
int a[N],d[N];
int n;
vector<int>g[N];
int ans=-INF;
void init(){
    for(int i=0; i<N; i++)
        g[i].clear();
    for(int i=0; i<n; i++)
        d[i]=INF;
}
void dfs(int u,int f){
    int tmp=lower_bound(d,d+n,a[u])-d;
    ans=max(ans,tmp+1);
    int t=d[tmp];
    d[tmp]=a[u];
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==f)
            continue;
        dfs(g[u][i],u);
    }
    d[tmp]=t;
}
int main(){
    //int n;
    while(scanf("%d",&n)==1){
        init();
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1; i<n; i++){
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=1; i<=n; i++)
            dfs(i,0);
        printf("%d\n",ans);
    }
    return 0;
}