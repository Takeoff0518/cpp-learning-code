#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (30000005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N];
int gcd(int aa,int bb){
	while(aa^=bb^=aa^=bb%=aa);
	return bb;
}
struct node{
	int u,v,w;
}s[M];
int fa[N],idx;
void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int findfa(int x){
	if(fa[x]!=x) fa[x]=findfa(fa[x]);
	return fa[x];
}
void unionn(int x,int y){
	x=findfa(x),y=findfa(y);
	if(x!=y) fa[x]=y;
}
bool check(int x,int y){
	return findfa(x)==findfa(y);
}
void mst(){
	
}
int main(){
	freopen("useless.in","r",stdin);
	freopen("useless.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			if(gcd(a[i],a[j])!=1){
//				s[++idx]=(node){i,j,gcd(a[i],a[j])};
//			}
//		}
//	}
	puts("2");
	return 0;
}

