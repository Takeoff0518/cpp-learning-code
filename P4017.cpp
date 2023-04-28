#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (5005)
#define M (500005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (80112002)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
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
int in[N],out[N],f[N],ans;
queue<int> q;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1,u,v;i<=m;i++){
        scanf("%d %d",&u,&v);
        add(u,v); in[v]++,out[u]++;
    }
    for(int i=1;i<=n;i++)
        if(in[i]==0){
            q.push(i); f[i]=1;
        }
    while(!q.empty()){
        int t=q.front(); q.pop();
        for(int i=head[t];i;i=edge[i].nxt){
            int j=edge[i].to; in[j]--;
            f[j]=(f[j]+f[t])%mod;
            if(in[j]==0) q.push(j);
        }
    }
    for(int i=1;i<=n;i++){
        if(out[i]==0) ans=(ans+f[i])%mod;
    }
    printf("%d\n",ans);
    return 0;
}