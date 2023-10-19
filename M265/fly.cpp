#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (20005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
int p[N];
int a[N];
struct node{
	int s,t;
	bool operator < (const node &x) const{
		return x.s==s ? x.t>t : x.s>s;
	}
}s[N];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=m;i++) scanf("%d %d",&s[i].s,&s[i].t);
	sort(p+1,p+n+1); sort(s+1,s+m+1);
	
//	for(int i=1;i<=n;i++) printf("%d ",p[i]);
//	puts("");
//	for(int i=1;i<=m;i++) printf("%d %d\n",s[i].s,s[i].t);
//	puts("");
	
	int pn=1,pm=1,ans1=0;
	while(pn<=n && pm<=m){
		if(s[pm].s<=p[pn] && p[pn]<=s[pm].t)
			ans1++,pn++,pm++;
		else if(p[pn]>s[pm].t) pm++;
		else if(p[pn]<s[pm].s) pn++;
	}
	pn=n,pm=m; int ans2=0;
	while(pn>=1 && pm>=1){
		if(s[pm].s<=p[pn] && p[pn]<=s[pm].t)
			ans2++,pn--,pm--;
		else if(p[pn]>s[pm].t) pn--;
		else if(p[pn]<s[pm].s) pm--;
	}
//	printf("%d %d\n",ans1,ans2);
	printf("%d\n",max(ans1,ans2));
    return 0;
}

