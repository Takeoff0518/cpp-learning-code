#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define N 100005
using namespace std;
int scc_cnt,stk[N],top;
int dfn[N],low[N],timestamp;
int dout[N],din[N];
int id[N];
bool in_stk[N];
struct E{
    int nxt,to;
}edge[N];
int head[N],num_edge;
void add(int from,int to){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    head[from]=num_edge;
}
void tarjan(int u){
    dfn[u]=low[u]=++timestamp;
    stk[++top]=u;
    in_stk[u]=1;
    for(int i=head[u];i;i=edge[i].nxt){
        int j=edge[i].to;
        if(!dfn[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
        }else if(in_stk[j]){
            low[u]=min(low[u],dfn[j]);
        }
    }
    if(dfn[u]==low[u]){
        ++scc_cnt;
        int y;
        do{
            y=stk[top--];
            in_stk[y]=0;
            id[y]=scc_cnt;
        }while(y!=u);
    }
}
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        while(cin>>t,t){
            add(i,t);
        }
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=head[i];j;j=edge[j].nxt){
            int k=edge[j].to;
            int a=id[i],b=id[k];
            if(a!=b){
                dout[a]++;
                din[b]++;
            }
        }
    }
    int a=0,b=0;
    for(int i=1;i<=scc_cnt;i++){
        if(!din[i]){
            a++;
        }
        if(!dout[i]){
            b++;
        }
    }
    printf("%d\n",a);
    if(scc_cnt==1){
        puts("0");
    }else{
        printf("%d\n",max(a,b));
    }
    return 0;
}