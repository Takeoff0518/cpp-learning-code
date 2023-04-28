#include<iostream>
#include<cstring>
#include<cstdio>
#define N 505
#define M 50005
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
int match[N],ans;
bool st[N];
bool find(int x){
    for(int i=head[x];i;i=edge[i].nxt){
        int j=edge[i].to;
        if(!st[j]){
            st[j]=true;
            if(match[j]==0 || find(match[j])){
                match[j]=x;
                return true; 
            }
        }
    }
    return false;
}
int n1,n2,m;
int main(){
    scanf("%d %d %d",&n1,&n2,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        add(a,b);
    }
    for(int i=1;i<=n1;i++){
        memset(st,false,sizeof(st));
        if(find(i)){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}