#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define INF 0x3f3f3f3f
#define ll long long
#define N 100005
#define M 200005
using namespace std;
struct E{
    int nxt,to;
    double dis;
}edge[M];
int head[N],num_edge;
void add(int from,int to,double dis){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    edge[num_edge].dis=dis;
    head[from]=num_edge;
}
int n,m;
double f[N];
int in[N],out[N];
void topsort(){
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=head[x];i;i=edge[i].nxt){
            int p=edge[i].to;
            f[p]+=(f[x]+edge[i].dis)/out[p];
            if(!--in[p]){  
                q.push(p);
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1,u,v;i<=m;i++){
        double w;
        scanf("%d %d %lf",&u,&v,&w);
        add(v,u,w);
        in[u]++,out[u]++;
    }
    topsort();
    printf("%.2lf",f[1]);
    return 0;
}