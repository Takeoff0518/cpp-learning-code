#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (100005)
#define M (1005)
#define logN (20)
#define INF (0x7f7f7f7f7f7f7f7f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
inline bool gmx(ll &a,ll b){
    return b>a?a=b,1:0;
}
int n,m,q;
int a[N],b[N];
int Log[N];
ll a_max[N][logN],a_min[N][logN],a_fmax[N][logN],a_zmin[N][logN];
ll b_max[N][logN],b_min[N][logN];
void init(){
	for(int i=1;i<=max(n,m);i++) Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;i++){
		a_max[i][0]=a_min[i][0]=a[i];
		if(a[i]<0) a_fmax[i][0]=a[i];
		else a_fmax[i][0]=-INF;
		if(a[i]>=0) a_zmin[i][0]=a[i];
		else a_zmin[i][0]=INF;
	}
	for(int i=1;i<=m;i++){
		b_max[i][0]=b_min[i][0]=b[i];
	}
	for(int j=1;j<=logN;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			//f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
			a_max[i][j]=max(a_max[i][j-1],a_max[i+(1<<j-1)][j-1]);
			a_fmax[i][j]=max(a_fmax[i][j-1],a_fmax[i+(1<<j-1)][j-1]);
			a_min[i][j]=min(a_min[i][j-1],a_min[i+(1<<j-1)][j-1]);
			a_zmin[i][j]=min(a_zmin[i][j-1],a_zmin[i+(1<<j-1)][j-1]);
		}
	}
	for(int j=1;j<=logN;j++){
		for(int i=1;i+(1<<j)-1<=m;i++){
			b_max[i][j]=max(b_max[i][j-1],b_max[i+(1<<j-1)][j-1]);
			b_min[i][j]=min(b_min[i][j-1],b_min[i+(1<<j-1)][j-1]);
		}
	}
}
int main(){
//	freopen("game13.in","r",stdin);
//	freopen("out.out","w",stdout);
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
	Log[0]=-1;
	init();
	while(q--){
		int l1,r1,l2,r2;
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		ll s1=Log[r1-l1+1],s2=Log[r2-l2+1];
		ll amax=max(a_max[l1][s1],a_max[r1-(1<<s1)+1][s1]);
		ll amin=min(a_min[l1][s1],a_min[r1-(1<<s1)+1][s1]);
		ll afmax=max(a_fmax[l1][s1],a_fmax[r1-(1<<s1)+1][s1]);
		ll azmin=min(a_zmin[l1][s1],a_zmin[r1-(1<<s1)+1][s1]);
		ll bmax=max(b_max[l2][s2],b_max[r2-(1<<s2)+1][s2]);
		ll bmin=min(b_min[l2][s2],b_min[r2-(1<<s2)+1][s2]);
		ll ans=-INF;
		gmx(ans,amax*(amax>=0?bmin:bmax));
        gmx(ans,amin*(amin>=0?bmin:bmax));
		if(afmax!=-INF)
			gmx(ans,afmax*(afmax>=0?bmin:bmax));
		if(azmin!=INF)
			gmx(ans,azmin*(azmin>=0?bmin:bmax));
		printf("%lld\n",ans);
	}
    return 0;
}
//F**k CCF!!!!!

