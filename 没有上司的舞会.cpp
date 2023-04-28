#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (6005)
#define M (6005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,h[N],f[N][2];
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
bool has_father[N];
/*
f[u][0] 所有以u为根的子树中选择，并且不选择u这个点的方案
f[u][1] 所有以u为根的子树中选择，并且选择u这个点的方案
*/
void dfs(int u){
    f[u][1]=h[u];
    for(int i=head[u];i;i=edge[i].nxt){
        int j=edge[i].to;
        dfs(j);
        f[u][0]+=max(f[j][0],f[j][1]);
        f[u][1]+=f[j][0];
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    for(int i=0,u,v;i<n-1;i++){
        scanf("%d %d",&u,&v);
        has_father[u]=1;
        add(v,u);
    }
    int root=1;
    while(has_father[root]) root++;
    dfs(root);
    printf("%d\n",max(f[root][0],f[root][1]));
    return 0;
}