#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
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
ll a[N],pre[N];
ll f[N];
ll st;
inline ll _abs(ll x){
	return x>0 ? x : -x; 
}
inline ll query(int l,int r){
	return pre[r]-pre[l-1];
} 
int ans_len; ll ans_val=INF;

const double CLOCKS_PER_SECOND=((clock_t)1000);
ll lim=1920*CLOCKS_PER_SECOND;
struct node{
	ll val;
	int idx;
	bool operator < (const node &x) const{
		return x.val>val;
	}
}s[N];
void bf(){
//	for(int i=1;i<=n;i++){
//		printf("%d ",pre[i]);
//	}puts("");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			ll val=abs(query(j,i));
			if(val<ans_val){
				ans_val=val;
				ans_len=i-j+1; 
			}else if(val==ans_val && ans_len<i-j+1){
				ans_val=val;
				ans_len=i-j+1; 
			}
//			if(1000*(clock()-st)>=lim){
//				printf("%lld\n%d\n",ans_val,ans_len);
//				return 0;
//			}
		}
	}
}
void rt(){
	sort(s+1,s+n+1);
	for(int i=2;i<=n;i++){
		ll val=abs(s[i].val-s[i-1].val);
//		printf("val:%d\n",val);
		if(val<ans_val){
			ans_val=val;
			ans_len=abs(s[i].idx-s[i-1].idx); 
		}else if(val==ans_val && ans_len<abs(s[i].idx-s[i-1].idx)){
			ans_len=abs(s[i].idx-s[i-1].idx);
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i].val==ans_val && ans_len<s[i].idx){
			ans_len=s[i].idx;
		}
	}
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
//	st=clock();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		pre[i]=pre[i-1]+a[i];
		s[i].val=s[i-1].val+a[i];
		s[i].idx=i;
	}
	if(n>=8000) rt();
	else bf();
//	bf();
//	rt();
//	for(int i=1;i<=n;i++){
//		printf("%d ",s[i].val);
//	}puts("awa");
//	for(int i=1;i<=n;i++){
//		printf("%d ",s[i].idx);
//	}puts("awa");
	printf("%lld\n%d\n",ans_val,ans_len);
    return 0;
}

