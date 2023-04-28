#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define INF 0x3f3f3f3f
#define ll long long
#define N 100005
#define M 500005
using namespace std;
struct Edge{
    struct E{
    int nxt,to,dis;
    }edge[M];
    int head[N],num_edge;
    void add(int from,int to,int dis){
        num_edge++;
        edge[num_edge].nxt=head[from];
        edge[num_edge].to=to;
        edge[num_edge].dis=dis;
        head[from]=num_edge;
    }
};
Edge s0,s1,s2;
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1,a,b,p,q;i<=m;i++){
        scanf("%d %d %d %d",&a,&b,&p,&q);
        s1.add(a,b,p);
        s2.add(a,b,q);
    }
    return 0;
}