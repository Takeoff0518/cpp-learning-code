//#include<algorithm>
//#include<iostream>
//#include<cstring>
//#include<cstdio>
#include<bits/stdc++.h>
#define N (10005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N],f[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		f[i]=a[i]-a[i-1];
		printf("%d ",f[i]);
	}
    return 0;
}
//F**k CCF!!!!!

