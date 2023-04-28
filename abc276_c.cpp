#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=105,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	prev_permutation(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
    return 0;
}
//F**k CCF!!!!!

