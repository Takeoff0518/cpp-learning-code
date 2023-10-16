#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (10000005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
#define x first
#define y second
using namespace std;
int a[N],n;
ll ans=0;
int main(){
	freopen("unija.in","r",stdin);
	freopen("unija.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1,x,y;i<=n;i++){
		cin>>x>>y;
		x/=2,y/=2;
		a[x]=max(a[x],y);
	}
	for(int h=0,i=N;i>=1;i--){
		h=max(h,a[i]);
		ans+=h;
	}
	cout<<(ans<<2)<<endl;
    return 0;
}

