#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (500005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0' && ch<='9'){ x=(x<<1)+(x<<3)+(ch^48); ch=getchar();}
	return x*f;
}
int n,a[N];
int money,add,ans;
int main(){
	freopen("sun.in","r",stdin);
	freopen("sun.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		if(money>=-a[i]){
			money+=add;
			add+=a[i];
			ans++;
//			printf("%d OK: money=%d, add=%d, day=%d\n",i,money,add,ans);
		}
		if(money+add<0){
			printf("%d\n",-1);
			return 0;
		}
		while(money<-a[i]){
			money+=add;
			ans++;
//			printf("%d WA: money=%d, add=%d, day=%d\n",i,money,add,ans);
		}
	}
	printf("%d\n",ans);
	return 0;
}
