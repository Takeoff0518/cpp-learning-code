#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<random>
#include<ctime>
#include<cstdlib>
#define N (5005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,k;
int a[N][N];
bool f[N][N];
void part_0(){
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			a[i][j]=(rand()%n)+1;
		}
	}
	for(int i=1;i<=n;i++) a[i][1]=i;
}
int get_next_1(int pre){
	for(int i=1;i<=n;i++){
		if(!f[pre][i] && !f[i][pre]){
			f[pre][i]=f[i][pre]=1;
			return i;
		}
	}
	return 0;
}
bool tong[N];
int get_next_2(int pre){
	for(int i=1;i<=n;i++){
		if(!f[pre][i] && !f[i][pre] && !tong[i]){
			f[pre][i]=f[i][pre]=tong[i]=1;
			return i;
		}
	}
	return 0;
}
int shuf[N];
void part_1(){
	for(int i=1;i<=n;i++) shuf[i]=i;
	random_shuffle(shuf+2,shuf+n+1); 
	for(int i=1;i<=n;i++){
		a[i][1]=shuf[i];
//		memset(f,0,sizeof(f));
		for(int j=2;j<=i;j++){
			a[i][j]=get_next_1(a[i][j-1]);
		}
	}
}
void part_2(){
	for(int i=1;i<=n;i++) shuf[i]=i;
	random_shuffle(shuf+2,shuf+n+1); 
	for(int i=2;i<=n;i++){
		a[i][1]=shuf[i];
		memset(tong,0,sizeof(tong));
		tong[shuf[i]]=1;
		for(int j=2;j<=i;j++){
			a[i][j]=get_next_2(a[i][j-1]);
		}
	}
}
int main(){
	scanf("%d %d",&n,&k);
	srand(time(0));
	a[1][1]=1;
	if(k==0){
		part_0();
	}else if(k==1){
		part_1();
	}else{
		part_2();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

