#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,t,a,b;
int ans=0;
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d %d %d %d",&n,&t,&a,&b);
	while(t--){
		int x;
		scanf("%d",&x);
		if(a>b) swap(a,b);
		if(x<=a){
			ans+=a-x;
			a=x;
		}else if(x>a && x<=b){
			if(x-a>b-x){
				ans+=b-x;
				b=x;
			}else{
				ans+=x-a;
				a=x;
			}
		}else{
			ans+=x-b;
			x=b;
		}
		
	}
	printf("%d\n",ans);
	return 0;
}

