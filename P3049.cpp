#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (100005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n;
ll a[N],b[N],x,y,z;
priority_queue<ll> q1,q2;
ll ans=0;
int main(){
	scanf("%d %lld %lld %lld",&n,&x,&y,&z);
	for(int i=1;i<=n;i++) scanf("%lld %lld",&a[i],&b[i]);
	for(int i=1;i<=n;i++){
		if(a[i]<b[i]){
			for(int j=1;j<=b[i]-a[i];j++){
				if(q2.empty() || z*i-q2.top()>x){
					ans+=x;
					q1.push(z*i+x);
				}else {
					ll g=q2.top();
					ans+=z*i-g;
					q2.pop();
					q1.push(z*i+z*i-g);
				}
			}
		}else if(a[i]>b[i]){
			for(int j=1;j<=a[i]-b[i];j++){
				if(q1.empty() || z*i-q1.top()>y){
					ans+=y;
					q2.push(z*i+y);
				}else {
					ll g=q1.top();
					ans+=z*i-g;
					q1.pop();
					q2.push(z*i+z*i-g);
				}
			}
		}
	}
	printf("%lld\n",ans);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

