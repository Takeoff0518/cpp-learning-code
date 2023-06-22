#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n;
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
int f[N][2];// 0 不参加 1 参加
int c[N];
bool father[N];
void dfs(int u){
    f[u][1]=c[u];
    for(int i=head[u];i;i=edge[i].nxt){
        int j=edge[i].to;

        dfs(j);
        f[u][0]+=max(f[j][0],f[j][1]);
        f[u][1]+=f[j][0];
    }
}
int rt,in[N];
int main(){
    // memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for(int i=1,u,v;i<=n;i++){
        scanf("%d %d",&u,&v);
        u++,v++;
        in[u]++;
        scanf("%d",&c[v]);
        add(v,u);
        father[u]=1;
    }
    if(in[1]==1)
    rt=1;
    else
    rt=2;
    while(father[rt]) rt++;
    dfs(rt);
    // printf("%d\n",rt);
    printf("%d\n",max(f[rt][0],f[rt][1]));
    return 0;
}