#include<iostream>
#include<cstdio>
#define N 10005
using namespace std;
int dfn[N],low[N],timestamp;
int stk[N],top;
int id[N];
int scc_cnt;
bool in_stk[N];
int head[N],num_edge;
struct Edge{
    int nxt,to,dis;
}edge[N];
void add(int from,int to,int dis){
    num_edge++;
    edge[num_edge].nxt=head[from];
    edge[num_edge].to=to;
    edge[num_edge].dis=dis;
    head[from]=num_edge;
}
/*
Tarjan算法求强连通分量(SCC)对每个点定义两个时间戳：dfn[u]表示遍历到u的时间戳
low[u]从u开始走，所能遍历到的最小时间戳是什么。
u是其所在的强联通分量的最高点，等价于dfn[u]==low[u]。
复杂度：O(n+m)
*/
void tarjan(int u){
    dfn[u]=low[u]=++timestamp;//更新
    stk[++top]=u;//将当前的点加入栈中
    in_stk[u]=1;//标记该点是否在栈中
    for(int i=head[u];i!=-1;i=edge[i].nxt){//遍历u所有能到的点
        int j=edge[i].to;
        if(!dfn[j]){//如果该点没有被遍历过
            tarjan(j);//遍历该点
            low[u]=min(low[u],low[j]);//看u能到的点的最小值，j能到，u也能到，进行更新
        //栈中不仅仅只存该条路径上的点，也有可能存其他点
        //栈中所有的点，都不是它所在的强连通分量的最高点
        //没搜完的点都在栈中
        }else if(in_stk[j]){//如果当前的点仍在栈中
            low[u]=min(low[u],dfn[j]);//用当前遍历的点j更新u的值
        }
    }
    if(dfn[u]==low[u]){//如果u能到的最早的点就是自己了，那么u必定是它所在强联通分量的最高点
        int y;
        scc_cnt++;
        do{
            y=stk[top--];//每次取出栈顶元素
            in_stk[y]=0;//标记这个点已经出栈了
            id[y]=scc_cnt;//标记这个点所在的强联通分量
        }while(y!=u);//当y==u时，说明已经把这个点所在的强联通分量处理完了
    }
}
int main(){
    
    return 0;
}