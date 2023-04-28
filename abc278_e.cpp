#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (305)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,num,nn,mm;
bool a[N][N][N];
int f[N][N][N];
int get_ans(int t,int x1,int y1,int x2,int y2){
	//s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]
	return f[t][x2][y2]-f[t][x1-1][y2]-f[t][x2][y1-1]+f[t][x1-1][y1-1];
}
int all[N];
int main(){
	scanf("%d %d %d %d %d",&n,&m,&num,&nn,&mm);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int t;
			scanf("%d",&t);
			a[t][i][j]=1;
			//cout<<t<<" ";
			//printf("%d ",f[t][i][j]);
		}
		//s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	}
	for(int t=1;t<=num;t++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				f[t][i][j]+=f[t][i-1][j]+f[t][i][j-1]-f[t][i-1][j-1]+a[t][i][j];
			}
			//puts("");
		}
		//puts("-----");
	}
	for(int i=1;i<=num;i++){
		all[i]=get_ans(i,1,1,n,m);
		//printf("%d ",all[i]);
	}
	//puts("\n---");
	for(int i=1;i<=n-nn+1;i++){
		for(int j=1;j<=m-mm+1;j++){
			int ans=0;
			int ii=i+nn-1,jj=j+mm-1;//���½�
			for(int k=1;k<=num;k++){
				if(all[k]-get_ans(k,i,j,ii,jj)>0){
					ans++;
				}
			}
			printf("%d ",ans);
		}
		puts("");
	}
    return 0;
}
//F**k CCF!!!!!

