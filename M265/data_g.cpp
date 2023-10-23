#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<random>
#include<cstdlib> 
#include<ctime>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
void make(){
	srand(time(0)+rand());
	int maxx=1000;
	int n=100,m=100;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)
		printf("%d\n",rand()%maxx);
	for(int j=1;j<=m;j++){
		int s=rand()%maxx,t=rand()%maxx;
		if(s>t) swap(s,t);
		printf("%d %d\n",s,t);
	}
}
int main(){
//	freopen("fly2.in","w",stdout);
	while(1){
		make();
		system("pause");
	}
    return 0;
}

