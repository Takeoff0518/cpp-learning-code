#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1505)
#define M (3005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
struct E{
    int nxt,to;
}edge[M];
int head[N],num_edge;
int n,f[N][2];
// bool has_father[N];
void add(int from,int to){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    head[from]=num_edge;
}
void dfs(int u,int fa){
    // printf("%d\n",u);
    f[u][1]=1,f[u][0]=0;
    for(int i=head[u];i;i=edge[i].nxt){
        int j=edge[i].to; 
        if(j==fa) continue;
        dfs(j,u);
        // 如果不放置，他的儿子都得放置，因为要满足士兵可以看到所有的边
        f[u][0]+=f[j][1];
        // 如果当前节点放置士兵，它的子节点选不选已经不重要了
        f[u][1]+=min(f[j][0],f[j][1]); 
    }
}
int main(){
    scanf("%d",&n);
    // memset(head,~0,sizeof(head));
    for(int i=1,x,k;i<=n;i++){
        scanf("%d %d",&x,&k);
        for(int j=1,r;j<=k;j++){
            scanf("%d",&r);
            add(x,r); add(r,x);
        }
    }
    dfs(0,-1);
    printf("%d\n",min(f[0][0],f[0][1]));
    return 0;
}