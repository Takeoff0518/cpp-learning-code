#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int t,n;
//int a[N],b[N];
int sum[N],ans; 
void dfs(int x){
	if(x==ans) return;
	/*
		顺子 
	*/
	int k=0;//*1
	for(int i=3;i<=14;i++){
		if(sum[i]==0) k=0;
		else{
			k++;
			if(k>=5){
				for(int j=i;j>=i-k+1;j--) sum[j]--;
				dfs(x+1);
				for(int j=i;j>=i-k+1;j--) sum[j]++;				
			}
		}
	}
	k=0;//*2
	for(int i=3;i<=14;i++){
		if(sum[i]<=1) k=0;
		else{
			k++;
			if(k>=3){
				for(int j=i;j>=i-k+1;j--) sum[j]-=2;
				dfs(x+1);
				for(int j=i;j>=i-k+1;j--) sum[j]+=2;				
			}
		}
	} 
	k=0;//*3
	for(int i=3;i<=14;i++){
		if(sum[i]<=2) k=0;
		else{
			k++;
			if(k>=2){
				for(int j=i;j>=i-k+1;j--) sum[j]-=3;
				dfs(x+1);
				for(int j=i;j>=i-k+1;j--) sum[j]+=3;				
			}
		}
	}
	/*
		带 
	*/
	for(int i=2;i<=14;i++){
		if(sum[i]<=3){
			if(sum[i]<=2) continue;
			sum[i]-=3;
			for(int j=2;j<=15;j++){
				if(sum[j]<=0 || j==i) continue;
				sum[j]--;
				dfs(x+1);
				sum[j]++;
			}
			for(int j=2;j<=14;j++){
				if(sum[j]<=1 || j==i) continue;
				sum[j]-=2;
				dfs(x+1);
				sum[j]+=2;
			}
			sum[i]+=3;
		}else{
			sum[i]-=3;
			for(int j=2;j<=15;j++){
				if(sum[j]<=0 || j==i) continue;
				sum[j]--;
				dfs(x+1);
				sum[j]++;
			}
			for(int j=2;j<=14;j++){
				if(sum[j]<=1 || j==i) continue;
				sum[j]-=2;
				dfs(x+1);
				sum[j]+=2;
			}
			sum[i]+=3;
			sum[i]-=4;
			for(int j=2;j<=15;j++){
				if(sum[j]<=0 || j==i) continue;
				sum[j]--;
				for(int k=2;k<=15;k++){
					if(sum[k]<=0 || j==k) continue;
					sum[k]--;
					dfs(x+1);
					sum[k]++; 
				}
				sum[j]++;
			}
			for(int j=2;j<=14;j++){
				if(sum[j]<=1 || j==i) continue;
				sum[j]-=2;
				for(int k=2;k<=14;k++){
					if(sum[k]<=0 || j==k) continue;
					sum[k]-=2;
					dfs(x+1);
					sum[k]+=2; 
				}
				sum[j]+=2;
			}
			sum[i]+=4;
		}
	}
	for(int i=2;i<=15;i++)
		if(sum[i]) x++;
	ans=min(ans,x);
}
int main(){
	scanf("%d %d",&t,&n);
	while(t--){
		memset(sum,0,sizeof(sum));
		ans=INF;
		for(int i=1,a,b;i<=n;i++){
			scanf("%d %d",&a,&b);
			if(a==0) sum[15]++;//大小王在一起 
			else if(a==1) sum[14]++;//A往后放
			else sum[a]++;
		}
		dfs(0);
		printf("%d\n",ans);
	} 
    return 0;
}

