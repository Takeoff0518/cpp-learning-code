#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (500005)
#define M (100005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,cnt;
int x[N],f[N]; 
struct node{
	int nxt,to;
}e[M];
int h[N],idx;
void add(int from,int to){
	idx++;
	e[idx].nxt=h[from];
	e[idx].to=to;
	h[from]=idx;
}
bool vis[N];
int tmp;
void dfs(int xx){
//	printf("dfs:%d\n",xx);
	vis[xx]=1;
	tmp^=x[xx];
//	printf("-tmp=%d\n",tmp);
	for(int i=h[xx];i;i=e[i].nxt){
		int j=e[i].to;
		if(!vis[j]){
//			int ttmp=x[j];
			dfs(j);
//			vis[j]=0,tmp=ttmp;
		}
	}
}
bool num[N];
int solve(){
	int ans=1;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			tmp=0;
//			printf("goto:%d\n",i);
			dfs(i);
//			printf("tmp=%d\n",tmp);
			ans*=tmp;
		}
	}
//	printf("ans=%d\n",ans);
	return ans;
}
void gen(int xx){
//	printf("gen:%d\n",xx);
	if(xx==n+1){
//		for(int i=2;i<=n;i++) printf("%d",num[i]);
//		printf("\n");
		memset(vis,0,sizeof(vis));
		memset(h,0,sizeof(h)); idx=0;
		for(int i=2;i<=n;i++){
			if(num[i]){
				add(f[i],i); add(i,f[i]);
//				printf("add: %d <-> %d\n",f[i],i);
			}
		}
		cnt+=solve();
		return;
	}
	num[xx]=1; gen(xx+1);
	num[xx]=0; gen(xx+1);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=2;i<=n;i++){
		scanf("%d",&f[i]);
	}
	gen(2);
	printf("%d\n",cnt);
    return 0;
}

