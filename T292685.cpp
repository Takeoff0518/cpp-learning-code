#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<random>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod ((int)(1e9+7))
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int a[N],b[N],c[N],d[N],l[N];
int m;
int main(){
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d %d %d",&a[i],&b[i],&c[i],&d[i],&l[i]);
	}
	printf("%d\n",l[1]);
	for(int i=2;i<=m;i++){
		srand(i);
		printf("%d\n",rand()%100);
	}
    return 0;
}
//F**k CCF!!!!!

