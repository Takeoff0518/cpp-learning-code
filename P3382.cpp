//#include<algorithm>
//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<cmath>
//#include<random>
//#include<cstdlib>
#include<bits/stdc++.h>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
const double eps=1e-15;
const double down=0.996;
using namespace std;
int n;
struct node{
	int x,y,w;
}s[N];
double ans_x,ans_y,ans_w;
double calc(double x,double y){
	double r=0.0,dx,dy;
	for(int i=1;i<=n;i++){
		dx=x-s[i].x;
		dy=y-s[i].y;
		r+=sqrt(dx*dx+dy*dy)*s[i].w;
	}
	return r;
}
void sa(){
	double T=3000.0;
	while(T>eps){
		double e_x=ans_x+(rand()*2.0-RAND_MAX)*T;
		double e_y=ans_y+(rand()*2.0-RAND_MAX)*T;
		double e_w=calc(e_x,e_y);
		double delta_e=e_w-ans_w;
		if(delta_e<0.0){
			ans_x=e_x,
			ans_y=e_y;
			ans_w=e_w;
		}else if(exp(-delta_e/T)*RAND_MAX>rand()){
			ans_x=e_x;
			ans_y=e_y;
		}
		T*=down;
	}
}
inline void solve(int x){
	for(int i=1;i<=x;i++) sa();
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&s[i].x,&s[i].y,&s[i].w);
		ans_x+=s[i].x;
		ans_y+=s[i].y;
	}
	ans_x/=(n*1.0),ans_y/=(n*1.0),ans_w=calc(ans_x,ans_y);
	solve(2);
	printf("%.3lf %.3lf\n",ans_x,ans_y);
    return 0;
}
//F**k CCF!!!!!

