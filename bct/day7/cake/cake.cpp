#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (40005)
#define M (100005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,lmt[N];
int ans=0;
int tong[M],cnt[M];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&lmt[i]);
	for(int i=1,x;i<=m;i++){
		scanf("%d",&x);
		tong[x]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1 && j>=i-8;j--){
			while(tong[j]>0 && lmt[i]>0){
				lmt[j]--;
				lmt[j+1]--;
				lmt[j+2]--;
				lmt[j+3]--;
				lmt[j+4]--;
				lmt[j+5]--;
				lmt[j+6]--;
				lmt[j+7]--;
				lmt[j+8]--;
				ans++,tong[j]--;
			}
			if(lmt[i]==0) break;
		}
	}
	printf("%d\n",ans);
	return 0;
}

