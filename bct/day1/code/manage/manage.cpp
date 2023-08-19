#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define N (500005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
int a[M],bul[N],box[N],fin[N];
int main(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++){ //空间大小 
		memset(box,0,sizeof(box));
		memset(bul,0,sizeof(bul));
		int ans=0;
		for(int i=1;i<=m;i++){ //枚举 a_i 
			int minTick=INF,minLoc=-1;
			bool flag=false;
			for(int j=1;j<=k;j++){ //枚举每个格子 
				if(!box[j]){
					box[j]=a[i],
					bul[a[i]]++;
					fin[j]=i;
					ans++;
					flag=true;
					break;
				}
				else if(box[j]==a[i]){
					fin[j]=i;
					flag=true;
					break;
				}
				else{
					if(minTick>fin[j]){
						minTick=fin[j];
						minLoc=j;
					}
				}
			}
			if(!flag && minTick!=INF){
				box[minLoc]=a[i];
				bul[a[i]]++;
				ans++;
				fin[minLoc]=minTick;
			}
		}
		printf("%d ",ans);
	}
	return 0;
}

