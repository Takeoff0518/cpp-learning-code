#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,a[N],d[N],cnt_1,cnt_2,minans,ans;
int solve(){
	int maxx=-INF;
	for(int i=1;i<=n;i++){
		d[i]=max(d[i-1]+a[i],a[i]);
		maxx=max(d[i],maxx);
	}
	return maxx;
}
int rt(){
	if(cnt_2<=(n+1)/2){
		for(int i=1;i<=n;i++){
			if(cnt_2 && !(i&1)){
				cnt_2--;
				a[i]=-1;
			}else a[i]=1;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(cnt_1 && i&1){
				cnt_1--;
				a[i]=1;
			}else a[i]=-1;
		}
	}
	return solve();
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) cnt_1++;
		else cnt_2++;
	}
	minans=rt();
	sort(a+1,a+n+1);
	do{
		int tmp=solve();
		if(tmp==minans) ans++;
	}while(next_permutation(a+1,a+n+1));
	printf("%d\n",ans%p);
    return 0;
}
//F**k CCF!!!!!

