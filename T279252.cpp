#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll long long
const int N=1e4,M=1e4;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
ll t,n;
char buf_ans[114];
ll next_n(double last_ans=0,ll get_n=0){
	//last_ans<n<=1e18
	sprintf(buf_ans,"%.6f",last_ans);
	for(ll i=0,x=0;;i++){
		if(buf_ans[i]=='.')return get_n^x;
		if(i&1)x*=10;
		else x=x*10+(buf_ans[i]^48);
	}
}
double ans=0.0;
inline double f(int x){
    return floor(pow(x,0.25)+0.5);
}
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        n=next_n(ans,n);
        ans=0.0;
        for(ll i=1;i<=n;i++){
            ans+=1.0/f(i);
        }
        printf("%.6lf\n",ans);
    }
	return 0;
}