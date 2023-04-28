#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define INF 0x3f3f3f3f
#define N 40005
#define M 80005
using namespace std;
// int f[N][N]; - f[i][j]表示从i开始，向上走2^j步所能走到的结点（0≤j≤logn）
//int depth[N]; - 表示深度（到根节点的距离+1）
/*
1.先将两个点跳到同一层
    二进制拼凑思想，从2^0,2^1,...,2^k中拼凑出t。
    只要t大于等于2^k，t中一定包含k这一位
2.让两个点同时往上跳，一直跳到它们的最近公共祖先的下一层（便于判断）

预处理 O(nlogn)
查询O(logn)

防止跳出：
    哨兵：如果从i开始跳2^j步会跳过根节点，那么fa[i][j]=0,depth[0]=0
*/
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
int n,m;
int fa[N][16],depth[N];
queue<int> q;
void bfs(int root){//宽度优先搜索
    memset(depth,0x3f,sizeof(depth));
    depth[0]=0;//哨兵规定为0
    depth[root]=1;//根节点规定为1
    q.push(root);//根节点入队
    while(!q.empty()){
        int t=q.front();//取出队头元素
        q.pop();
        for(int i=head[t];i;i=edge[i].nxt){
            int j=edge[i].to;
            if(depth[j]>depth[t]+1){//如果还没有被搜索过
                depth[j]=depth[t]+1;
                q.push(j);
                fa[j][0]=t;//跳1步到t
                for(int k=1;k<=15;k++){
                    fa[j][k]=fa[fa[j][k-1]][k-1];
                }
            }
        }
    }
}
int lca(int a,int b){
    if(depth[a]<depth[b]){
        swap(a,b);
    }
    for(int k=15;k>=0;k--){
        if(depth[fa[a][k]]>=depth[b]){//如果从a开始，跳2^k步后，仍然在b的下面后者是在同一层
            a=fa[a][k];//a跳
        }
    }
    if(a==b){
        return a;
    }
    for(int k=15;k>=0;k--){
        if(fa[a][k]!=fa[b][k]){//如果还没有找到祖先
            a=fa[a][k];
            b=fa[b][k];
        }
    }
    return fa[a][0];
}
int main(){
    scanf("%d",&n);
    int root=0;
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(b==-1){
            root=a;
        }else{
            add(a,b);
            add(b,a);
        }
    }
    bfs(root);
    scanf("%d",&m);
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        int p=lca(a,b);
        if(p==a){
            puts("1");
        }else if(p==b){
            puts("2");
        }else{
            puts("0");
        }
    }
    return 0;
}