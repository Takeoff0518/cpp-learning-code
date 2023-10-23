#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
int a[N];
struct T{
	int val,tag;
}t[N<<2];
void upload(int p){
	t[p].val=t[ls(p)].val+t[rs(p)].val; 
}
int main(){

    return 0;
}

