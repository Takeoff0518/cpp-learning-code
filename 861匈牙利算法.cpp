#include<iostream>
#include<cstring>
#include<cstdio>
#define N 505
#define M 100005
int n1,n2,m;
int match[N];
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
bool find(int x){//匈牙利算法，复杂度 ≤ O(nm)
    for(int i=head[x];i;i=edge[i].nxt){//枚举二分图中所有与该点连接的点
        int j=edge[i].to;
        if(!st[j]){//如果没有匹配两个点
            st[j]=true;
            //如果j没有在前一个匹配中
            //或者i在匹配中，但是从i相邻的结点出发可以有增广路
            if(match[j]==0 || find(match[j])){
                match[j]=x;//记录查找成功记录
                return true;
            }
        }
    }
    return false;
}
int main(){
    scanf("%d %d %d",&n1,&n2,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d %d",&a,&b);//建立单向边
        add(a,b);
    }
    int ans=0;//匹配数量
    for(int i=1;i<=n1;i++){
        memset(st,false,sizeof(st));
        if(find(i)){//从结点i尝试扩展
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}