#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<random>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
const double eps=1e-10;
const double down=0.996;
int t,n;
double ans;
ll v[N];

double calc(){
	double suml=0,sumr=0;
	for(int i=1;i<=n/2;i++) suml+=v[i];
	for(int i=n/2+1;i<=n;i++) sumr+=v[i];
	return abs(suml-sumr);
}

void sa(){
	double T=3000;
	while(T>eps){
		int x=rand()%n+1,y=rand()%n+1;
		swap(v[x],v[y]);
		double e_ans=calc();
		double delta=e_ans-ans;
		if(delta<0) ans=e_ans;
		else if(exp(-delta/T)*RAND_MAX<=rand()){
			swap(v[x],v[y]);
		}
		T*=down;
	}
}
void solve(int x){
	while(x--) sa();
}
int main(){
	srand(time(0));
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&v[i]);
		if(n==1){
			printf("%lld\n",v[1]);
			continue;
		}
//		random_shuffle(v+1,v+n+1);
		ans=1e8;
		solve(100);
		cout<<ans<<endl;
	}
    return 0;
}

