#pragma GCC optimize(2)
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#define N (1000005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N],f[N];
stack<int> st;
int main(){
	freopen("number.in", "r", stdin),freopen("number.out", "w", stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	st.push(1);
	int ans=0;
	for(int i=2;i<=n;i++){
		if(a[st.top()]<a[i]) st.push(i);
		else if(a[i]>a[i-1]) f[i]=f[i-1]+1;
		else f[i]=1;
	}
	for(int i=1;i<=n;i++) ans=max(ans,f[i]);
	printf("%d\n",ans);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

