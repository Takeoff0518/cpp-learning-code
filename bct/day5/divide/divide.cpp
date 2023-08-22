#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (100)
#define M (1000005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,q;
int a[N],m[M]; 
int main(){
	freopen("divide.in","r",stdin);
	freopen("divide.out","w",stdout);
	scanf("%d %d",&a,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=q;i++){
		scanf("%d",&m[i]);
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",m[i]);
	}
	return 0;
}

