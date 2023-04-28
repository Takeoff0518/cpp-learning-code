#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
ll n,m,l,r,p;
ll ans=0;
ll gcd(ll a,ll b){
	while(a^=b^=a^=b%=a);
	return b;
}
int main(){
	cin>>n>>m>>l>>r>>p;
	l*=l,r*=r;
	for(int x1=0;x1<=n;x1++){
		for(int y1=0;y1<=m;y1++){
			for(int x2=0;x2<=n;x2++){
				for(int y2=0;y2<=m;y2++){
					if((x1>x2 || y1>y2)||(x1==x2 && y1==y2)){
						continue;
					}
					ll dis=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
					printf("(%d,%d),(%d,%d),dis=%d\n",x1,y1,x2,y2,dis);
					if(dis>=l && dis<=r && gcd(x2-x1,y2-y1)==1){
						
						//printf("(%d,%d),(%d,%d),dis=%d\n",x1,y1,x2,y2,dis);
						ans++;
						if(ans==p){
							ans=0;
						}
					}
				}
			}
		}
	}
	cout<<ans; 
    return 0;
}

