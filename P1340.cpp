#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 10005
#define M 10005
using namespace std;
int n,m;
int fa[N];
struct node{
    int u,v,w,idx;
}s[M];
inline bool cmp(node x,node y){
    return x.w<y.w;
}
int findfa(int x){
    if(x!=fa[x]){
        fa[x]=findfa(fa[x]);
    }
    return fa[x];
}
void unionn(int x,int y){
    x=findfa(x),y=findfa(y);
    fa[x]=y;
}
bool check(int x,int y){
    return findfa(x)==findfa(y);
}
int ans[N];
int kruskal(int k){
    int cnt=0,sum=0;
    //init
    for(int i=1;i<=k;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        if(cnt==k-1){
            break;
        }
        if(check(s[i].u,s[i].v)==0 && s[i].idx<=k){
            unionn(s[i].u,s[i].v);
            cnt++;
            sum+=s[i].w;
        }
    }
    if(cnt<k-1){
        return -1;
    }
    return sum;
}
int main(){
    scanf("%d %d",&n,&m);
    
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&s[i].u,&s[i].v,&s[i].w);
        s[i].idx=i;
    }
    sort(s+1,s+m+1,cmp);
    for(int i=m;i>=1;i--){
        ans[i]=kruskal(i);
        if(ans[i]==-1){
            for(int j=1;j<i;j++){
                ans[j]=-1;
            }
            break;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}