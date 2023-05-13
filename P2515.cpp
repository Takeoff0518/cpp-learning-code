#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
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
int id[N],low[N],timestamp,id[N],scc_cnt;
int n,m,w[N],v[N],d[N];
bool in_stk[N];
stack<int> st;
void tarjan(int u){
    low[u]=id[u]=++timestamp;
    st.push(u); in_stk[u]=1;
    for(int i=head[u];i;i=edge[i].nxt){
        int j=edge[i].to;
        if(!id[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
        }else if(in_stk[j]){
            low[u]=min(low[u],id[j]);
        }
    }
    if(low[u]==id[u]){
        int y;
        scc_cnt++;
        do{
            y=st.top(); st.pop();
            in_stk[y]=0; id[y]=scc_cnt;
        }while(y!=u);
    }
}
int in[N],f[N][N];
//f[i][j]:以i号点为根的子树中用不超过j的空间的最大价值
void solve(int u){
    
}
int main(){
    memset(head,-1,sizeof(head));
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);
    for(int i=1;i<=n;i++){
        if(d[i]) add(d[i],i);
    }
    for(int i=1;i<=n;i++){
        if(!id[i]) tarjan(i);
    }
    memset(head,-1,sizeof(head)); num_edge=0;
    for(int i=1;i<=n;i++){
        if(id[d[i]]!=id[i]){
            add(id[d[i]],id[i]);
            in[id[i]]++;
        }
    }
    for(int i=1;i<=scc_cnt;i++){
        if(!in[i]) add(0,i);
    }
    
    return 0;
}