#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<vector>
#define N (1000005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N];
int f[N],p[N];
stack<int> st;
void dd(){
	for(int i=n;i>=1;i--){
		while(!st.empty() && a[st.top()]<=a[i])
			st.pop();
		if(!st.empty()) f[i]=st.top()-i;
		else f[i]=n-i+1;
		st.push(i);
	}
}
int ans=0;
void part(){
	dd();
//	for(int i=1;i<=n;i++) printf("%d ",f[i]);
	for(int i=2;i<=n;i++){
		if(f[i-1]<=f[i]){
			p[i]=p[i-1]+1;
		}else{
			p[i]=1;
		}
	}
//	puts("");
	for(int i=1;i<=n;i++) printf("%d ",p[i]);
	puts("");
//	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,p[i]);
	printf("%d\n",ans);
}
void part2(){
	int minn=a[n];
	for(int i=n-1;i>=1;i--){
		if(a[i]>minn) ans++;
		else minn=a[i];
	}
}
int idx,tidx,lp;
bool vis[N];
void bf(){
	idx=n;
	while(1){
		tidx=idx;
		for(int i=2;i<=idx;i++){
			if(a[i-1]>a[i]) vis[i]=1,tidx--;
			else vis[i]=0;
		}
		int lp=0;
		for(int i=1;i<=idx;i++){
			if(!vis[i]) a[++lp]=a[i];
		}
//		for(int i=1;i<=tidx;i++) printf("%d ",a[i]);
//		puts("");
		if(tidx==idx) break;
		ans++;
		idx=tidx;	
	}
	printf("%d\n",ans);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=10000){
		bf();	
	}else{
		part();
	}
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

