#include<iostream>
#include<cstdio>
#include<cstring>
#define ull unsigned long long
#define ll long long
#define N 500005
using namespace std;
int n,m,tree[N];
int lowbit(int x){
	return x&(-x);
}
void add(int x,int k){//a[x]+=k
	while(x<=k){
		tree[x]+=k;
		x+=lowbit(x);
	}
}
int sum(int x){//1~x
	int ans=0;
	while(x!=0){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
} 
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		add(i,a);
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==1)
			add(b,c);
		else
			cout<<sum(c)-sum(b-1)<<endl;
	}
	return 0;
}

