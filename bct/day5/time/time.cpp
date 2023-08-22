#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#define N (15)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int k,n;
int a[N];
int ansn,anst=INF;
int stt;
void dfs(int xi,int xn,int xt,int nowt){
//	printf("goto: %d %d %d\n",xi,xn,xt);
//	printf("now: ansn->%d, anst->%d\n",ansn,anst);
	if(clock()-stt>=400){
//		printf("oops! %d %d\n",clock(),stt);
		printf("%d %d\n",ansn,anst);
		exit(0);
	}
//	if(xi==n+1){
	if(ansn<xn){
//		printf("update1: ansn->%d, anst->%d\n",ansn,anst);
		ansn=xn;
		anst=xt%1440;
	}else if(ansn==xn && anst>=xt%1440){
		ansn=xn;
		anst=xt%1440;
//		printf("update2: ansn->%d, anst->%d\n",ansn,anst);
	}
//		return;
//	}
	for(int i=xi+1;i<=n;i++){
//		printf("--for: %d\n",i);
		//没有超时的情况下选择这道题
		if(nowt+a[i]<=k){
			dfs(i,xn+1,xt*2+a[i],xt+a[i]);
		}  
	}
}
int main(){
	freopen("time.in","r",stdin);
	freopen("time.out","w",stdout);
	stt=clock();
	scanf("%d %d",&k,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		
//	}
	dfs(0,0,0,0);
	printf("%d %d\n",ansn,anst);
	return 0;
}

