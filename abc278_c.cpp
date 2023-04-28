#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
map<PII,bool> g;
int n,q;
int main(){
	scanf("%d %d",&n,&q);
	while(q--){
		int opt,x,y;
		scanf("%d %d %d",&opt,&x,&y);
		switch(opt){
			case 1:
				g[make_pair(x,y)]=1;
				break;
			case 2:
				g[make_pair(x,y)]=0;
				break;
			case 3:
				if(g[make_pair(x,y)] && g[make_pair(y,x)]) puts("Yes");
				else puts("No");
				break;
		}
	}
    return 0;
}
//F**k CCF!!!!!

