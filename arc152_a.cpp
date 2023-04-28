#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (200005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,l,cnt_1,cnt_2,a[N];
int main(){
	scanf("%d %d",&n,&l);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) cnt_1++;
		else cnt_2++;
	}
	int r=2,last;
	for(int i=1;i<=n;i++){
		if(a[i]==1) last=r,r+=2,cnt_1--;
		if(a[i]==2) last=r,r+=3,cnt_2--;
		if(r<=n-2 && r>=n+2){
			if((cnt_1 && cnt_2)||(cnt_1 && cnt_2)){
				puts("No");
				return 0;
			}else{
				puts("Yes");
				return 0;
			}
		}
//		if(r==n-1){
//			if(cnt_1 && cnt_2){
//				puts("No");
//				return 0;
//			}else{
//				puts("Yes");
//				return 0;
//			}
//		}
//		if(r==n){
//			if(cnt_1 && cnt_2){
//				puts("No");
//				return 0;
//			}else{
//				puts("Yes");
//				return 0;
//			}
//		}
	}
	if(cnt_2){
		puts("No");
	}else{
		puts("Yes");
	}
    return 0;
}
//F**k CCF!!!!!

