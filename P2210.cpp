//#include<algorithm>
//#include<iostream>
//#include<cstring>
//#include<cstdio>
#include<bits/stdc++.h>
#define N (20)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N][3],pos[N];
const double eps=1e-10;
const double down=0.996;
int ans;
int calc(){
	int tmp_ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			tmp_ans+=abs(pos[i]-pos[a[i][j]]);
		}
	}
	return tmp_ans;
}
void sa(){
	double T=5000;
	while(T>eps){
		int x,y;
		do{
			x=rand()%n+1;
			y=rand()%n+1;
		}while(x==y);
		swap(pos[x],pos[y]);
		int e_ans=calc();
		int delta_ans=ans-e_ans;
		if(delta_ans>=0){
			ans=e_ans;
		}else if(exp(-delta_ans/T)*RAND_MAX<rand()){
			swap(pos[x],pos[y]);
		}
		T*=down;
	} 
}
inline void solve(int x){
	for(int i=1;i<=x;i++) sa();
}
int main(){
	scanf("%d",&n);
	srand(time(0));
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		pos[i]=i;
	}
	ans=calc();
	solve(500);
	printf("%d\n",ans/2);
    return 0;
}
//F**k CCF!!!!!

