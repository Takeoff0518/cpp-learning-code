#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (42)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n;
int a[N][N];
int li,lj;
int main(){
	cin>>n;
	li=1,lj=n/2+1; 
	a[li][lj]=1;
	for(int i=2;i<=n*n;i++){
//		printf("%d %d\n",li,lj);
		if(li==1 && lj!=n){
//			puts("goto:1");
			li=n,lj=lj+1; 
		}else if(li!=1 && lj==n){
//			puts("goto:2");
			li=li-1,lj=1;
		}else if(li==1 && lj==n){
//			puts("goto:3");
			li=li+1;
		}else if(li!=1 && lj!=n){
			if(a[li-1][lj+1]==0){
//				puts("goto:4.1");
				li=li-1,lj=lj+1;
			}else{
//				puts("goto:4.2");
				li=li+1;
			}
		}
		a[li][lj]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		puts("");
	}
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

