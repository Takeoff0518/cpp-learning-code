#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1000005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,a[N];
int cnt_1=0,cnt_2=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) cnt_1++;
		else cnt_2++;
	}
	if(cnt_2<=(n+1)/2){
		for(int i=1;i<=n;i++){
			if(cnt_2 && !(i&1)){
				cnt_2--,a[i]=-1;
			}else a[i]=1;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(cnt_1 && i&1){
				cnt_1--,a[i]=1;
			}else a[i]=-1;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	puts("");
    return 0;
}
//F**k CCF!!!!!

