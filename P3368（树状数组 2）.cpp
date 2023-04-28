#include<iostream>
#include<cstdio>
#include<cstring>
#define ull unsigned long long
#define ll long long
#define N 500005
using namespace std;
int n,m,tree[N],a[N];
int lowbit(int x){
	return x&(-x);
}
void add(int x,int k){
	while(x<=k){
		tree[x]+=k;
		x+=lowbit(x);
	}
}
int sum(int x){
	int ans=0;
	while(x!=0){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int opt,x,y,k;
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d %d %d",&x,&y,&k);
			add(x,k);
			add(y+1,-k);
		}else if(opt==2){
			scanf("%d",&x);
			printf("%d\n",sum(x)+a[x]);
		}
	}
	return 0;
}

