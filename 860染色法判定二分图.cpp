#include<iostream>
#include<cstdio>
#define N 100005
#define M 200005
using namespace std;
int n,m;
int color[N];
bool st[N];
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
bool dfs(int u,int c){
    color[u]=c;
    for(int i=head[u];i;i=edge[i].nxt){
        int j=edge[i].to;
        if(!color[j]){
            if(!dfs(j,3-c)){
                return 0;
            }
        }else if(color[j]==c){
            return 0;
        }
    }
    return 1;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
        add(b,a);
    }
    bool flag=1;
    for(int i=1;i<=n;i++){
        if(!color[i]){
            if(!dfs(i,1)){
                flag=0;
                break;
            }
        }
    }

    for(int i=1;i<=n;i++){
        printf("%d ",color[i]);
    }
    puts("");

    if(flag){
        puts("Yes");
    }else{
        puts("No");
    }
    return 0;
}