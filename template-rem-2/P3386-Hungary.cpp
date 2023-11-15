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
struct E{
	int nxt,to;
}e[M];
int h[N],idx;
void add(int from,int to){
	e[++idx].nxt=h[from];
	e[idx].to=to;
	h[from]=idx;
}
int match[N];
bool st[N];
bool find(int x){
	for(int i=h[x];i;i=e[i].nxt){
		int j=e[i].to;
		if(!st[j]){
			st[j]=1;
			if(!match[j] || find(j)){
				match[j]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){

    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

