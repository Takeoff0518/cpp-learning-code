#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (100005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m1,m2;
struct node{
	int x,y;
	bool operator < (const node&xxxxx) const{
		return xxxxx.x>x;
	}
}a[N],b[N]; 
int res1[N],res2[N];
void solve(node *t,int m,int *res){
	priority_queue<PII,vector<PII>,greater<PII> > lq;
	priority_queue<int,vector<int>,greater<int> > wq;
	for(int i=1;i<=n;i++) wq.push(i);
	for(int i=1;i<=m;i++){
		while(!lq.empty() && t[i].x>=lq.top().first){
			wq.push(lq.top().second);
			lq.pop();
		}
		if(wq.empty()) continue;
		int dest=wq.top(); wq.pop();
		res[dest]++;
		lq.push({t[i].y,dest});
	}
	for(int i=1;i<=n;i++) res[i]+=res[i-1];
}
int main(){
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d %d",&a[i].x,&a[i].y);
	for(int i=1;i<=m2;i++)
		scanf("%d %d",&b[i].x,&b[i].y);
	sort(a+1,a+m1+1); sort(b+1,b+m2+1);
	solve(a,m1,res1); solve(b,m2,res2);
	int ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,res1[i]+res2[n-i]);
	}
	printf("%d\n",ans);
	return 0;
}
