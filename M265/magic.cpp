#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (10005)
#define M (405)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
int s[N],t[N];
int f[M][M];
const int si=400; 
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	for(int i=1;i<=n;i++) scanf("%d",&t[i]);
	memset(f,INF,sizeof(f));
	
	for(int i=1,a,b,c;i<=m;i++){
		scanf("%d %d %d",&a,&b,&c);
//		si=max(si,max(a,b));
		f[a][b]=c;
	}
	for(int i=1;i<=si;i++) f[i][i]=0;
	for(int i=1;i<=si;i++){
		for(int j=1;j<=si;j++){
			for(int k=1;k<=si;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=si;i++){
//		for(int j=1;j<=si;j++){
//			printf("%d ",f[i][j]==INF ? -1 : f[i][j]);
//		}
//		puts("");
//	}
//	puts("-=-=-=-=-");
	int ans=0;
	bool ff=0;
	for(int i=1,tmp;i<=n;i++){
//		printf("goto:%d\n",i);
		tmp=INF;
		if(s[i]==t[i]) continue;
		for(int j=1;j<=si;j++){
//			printf("f[%d][%d]=%d,f[%d][%d]=%d\n",s[i],j,f[s[i]][j],t[i],j,f[t[i]][j]);
			if(f[s[i]][j]!=INF && f[t[i]][j]!=INF && tmp>f[s[i]][j]+f[t[i]][j]){
//				printf("upd tmp:%d->%d\n",tmp,f[s[i]][j]+f[t[i]][j]);
				tmp=f[s[i]][j]+f[t[i]][j];
			}
		}
		if(tmp!=INF){
//			printf("final tmp=%d\n",tmp);
			ans+=tmp;
			
		}
		else ff=1;
	}
	printf("%d\n",ff ? -1 : ans);
    return 0;
}

