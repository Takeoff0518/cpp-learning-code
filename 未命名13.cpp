#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
struct E{
	int nxt,to,v;
}edge[M];
int head[N],num_edge;
void add(int from,int to,int dis){
	num_edge++;
	edge[num_edge].nxt=head[from];
	edge[num_edge].to=to;
	edge[num_edge].v=dis;
	head[from]=num_edge; 
}
int main(){

    return 0;
}
//F**k CCF!!!!!

