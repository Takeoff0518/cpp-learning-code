#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue> 
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,s;
struct E{
	int nxt,to,dis;
}e[M];
int h[N],idx;
void add(int from,int to,int dis){
	e[++idx].nxt=h[from];
	e[idx].to=to;
	e[idx].dis;
	h[from]=idx;
}

int main(){

    return 0;
}

