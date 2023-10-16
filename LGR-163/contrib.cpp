#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int t,n,r[N],c[N];
struct node{
	int r,c,id;
	bool operator < (const node &x) const{
		return x.r>r;
	} 
}s[N];
void solve(){
	scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&s[i].r),s[i].id=i;
    for(int i=1;i<=n;i++) scanf("%d",&s[i].c);
	sort(s+1,s+n+1);
	
}
int main(){
    scanf("%d",&t);
    while(t--){
    	solve();
	}
    return 0;
}
