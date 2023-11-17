#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<random>
#include<ctime>
#define N (10005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
const double eps=1e-5;
const double down=0.998;
int n;
ll a[N],b[N];
ll calc(){
	ll sq_sum=0,t=0,sum=0;
	for(int i=1;i<=n;i++){
        t+=b[i];
        sum+=t;
		sq_sum+=t*t;
	}
	return n*sq_sum-sum*sum;
}
ll ans;
void sa(){
	double T=10000;
	while(T>eps){
		int x,y;
		do{
			x=rand()%(n-1)+2;
			y=rand()%(n-1)+2;
		}while(x==y);
		swap(b[x],b[y]);
		ll e_ans=calc();
		ll delta=ans-e_ans;
		if(delta>0){
			ans=e_ans;
		}else if(exp(-delta/T)*RAND_MAX>rand()){
			swap(b[x],b[y]);
		}
		T*=down;
	}
}
int main(){
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	ans=calc();
	while(clock()*1000<900*CLOCKS_PER_SEC) sa();
	printf("%lld\n",ans);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

