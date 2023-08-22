#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
#define N (200005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
//using namespace __gnu_pbds;
//tree<double, null_type,\
//	greater<double>,\
//	rb_tree_tag,\
//	tree_order_statistics_node_update> t;
int n,m,a[N];
set<int> t;
int main(){
	freopen("delet.in","r",stdin);
	freopen("delet.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		t.insert(a[i]); 
	}
	for(int i=1,l,r;i<=m;i++){
		scanf("%d %d",&l,&r);
	}
	printf("%d\n",a[1]);
	return 0;
}

