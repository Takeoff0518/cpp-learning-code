#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (500005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N],b[N];
int check1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>a[j]) ans++;
		}
	}
	return ans;
}
bool check2(){
	for(int i=1;i<=n;i++){
		if(a[i]<b[i]) return 1;
	}
	return 0;
}
int main(){
	freopen("inversion.in","r",stdin);
	freopen("inversion.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	while(next_permutation(b+1,b+n+1)){
		if(check1() && check2()){
			for(int i=1;i<=n;i++) printf("%d ",b[i]);
			break;
		}
	}
	return 0;
}

