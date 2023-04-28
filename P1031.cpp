#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define INF 0x3f3f3f3f
#define N 1000005
#define M 2005
using namespace std;
int a[N],x,ansx,ans,n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		x+=a[i];
	}
	x/=n;
	for(int i=1;i<n;i++){
        a[i]-=x;
		if(a[i]!=0){
			ans++;
			a[i+1]+=a[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}