#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ull unsigned long long
#define ll long long
#define N 10005
using namespace std;
int lsh[N],idx,num[N],n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		lsh[i]=num[i];
	}
	sort(lsh+1,lsh+n+1);
	idx=unique(lsh,lsh+n+1)-lsh-1;
	for(int i=1;i<=n;i++){
		num[i]=lower_bound(lsh+1,lsh+idx+1,num[i])-lsh;
	}
	for(int i=1;i<=idx;i++){
		cout<<num[i]<<' ';
	}
	return 0;
}

