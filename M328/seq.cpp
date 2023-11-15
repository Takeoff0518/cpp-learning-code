#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (100005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,k;
int a[N],p[N];
ll ans=0;
//map<int,int> cnt;
inline int query(int &l,int &r){
	return p[r]^p[l-1];
}
void bf(){
	for(int i=1;i<=n;i++) p[i]=p[i-1]^a[i];
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans+=(query(i,j)>=k);
		}
	} 
} 
//void solve(){
//	for(int i=1;i<=n;i++){
//		p[i]=p[i-1]^a[i];
//		for(int j=31;j>=0;j--){
//			if((p[i]^(1<<j))<k) break;
//			ans+=cnt[p[i^(1<<j)]];
//		}
//		cnt[p[i]]++;
//	}
//}
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bf();
	for(int i=1;i<=n;i++) printf("%d ",p[i]);
	puts(""); 
	printf("%lld\n",ans);
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

