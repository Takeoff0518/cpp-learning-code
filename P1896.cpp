#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,k,num;
ll ans=0;
ll f[15][105][2005];
ll cnt[2005],ok[2005];
int main(){
	scanf("%d %d",&n,&k);
	for(int s=0;s<(1<<n);s++){
		int sum=0,tmp_s=s;
		while(tmp_s){
			if(tmp_s&1) sum++;
			tmp_s>>=1;
		}
		cnt[s]=sum;
		if((((s<<1)|(s>>1))&s)==0) ok[++num]=s;
	}
	f[0][0][0]=1;
//	for(int i=1;i<=num;i++) printf("%d ",ok[i]);
//	puts("");
//	for(int i=0;i<(1<<n);i++) printf("%d ",cnt[i]);
//	puts("");
	for(int i=1;i<=n;i++){
		for(int l=1;l<=num;l++){//第i行状态 
			int s1=ok[l];
			for(int r=1;r<=num;r++){//上一行状态 
				int s2=ok[r];
				if(((s2|(s2<<1)|(s2>>1))&s1)==0){
					for(int j=0;j<=k;j++){//枚举国王个数 
						if(j-cnt[s1]>=0)
							f[i][j][s1]+=f[i-1][j-cnt[s1]][s2];
					}
				}
			} 
		}
	}
	for(int i=1;i<=num;i++)
		ans+=f[n][k][ok[i]];
	printf("%lld\n",ans);
    return 0;
}
//F**k CCF!!!!!

