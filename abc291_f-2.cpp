#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
char t[N][15];
int f[2][N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",t[i]+1);
	memset(f,0x3f,sizeof(f));
	f[0][1]=f[1][n]=0;
	for(int i=1;i<=n;i++)
		for(int j=max(i-m,1);j<i;j++)
			if(t[j][i-j]=='1')
				f[0][i]=min(f[0][j]+1,f[0][i]);
	for(int i=n;i>=1;i--)
		for(int j=min(i+m,n);j>i;j--)
			if(t[i][j-i]=='1')
				f[1][i]=min(f[1][j]+1,f[1][i]);
	for(int i=2;i<n;i++){
		int ans=1e9;
		for(int j=max(i-m,1);j<i;j++)
			for(int k=i+1;k<=min(i+m,n);k++)
				if(k-j<=m&&t[j][k-j]=='1')
					ans=min(f[0][j]+f[1][k]+1,ans);
		printf("%d\n",ans==1e9?-1:ans);
	}return 0;
}
