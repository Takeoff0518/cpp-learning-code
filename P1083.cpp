#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1000005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m;
int a[N],c[N],l[N],r[N];
int pre[N];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&c[i],&l[i],&t[i]);
		pre[l[i]]+=c[i];
		pre[r[i]+1]-=c[i];
	}
	for(int i=1;i<=n;i++){
		
	}
    return 0;
}

