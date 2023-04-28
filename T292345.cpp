#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (100005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) ((xxx)<<1)
#define rs(xxx) ((xxx)<<1|1)
using namespace std;
priority_queue<ll> q;
int n,p,k;
ll a[N];
ll ans_chu,ans_zuo;
int main(){
//	freopen("harvest.in","r",stdin);
//	freopen("harvest2.out","w",stdout);
//	freopen("T292345.in","r",stdin); 
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	while(k--){
		ans_chu=ans_zuo=0;
		scanf("%d",&p);
		q.push(0);
		for(int i=1;i<=p-1;i++){
			q.push(a[i]);
		}
		for(int i=0;!q.empty();i++){
			if(p+i<=n) q.push(a[p+i]);
			//偶数：出题人
			//奇数：做题人
			if(i&1) ans_zuo+=q.top();
			else ans_chu+=q.top();
			q.pop();
		}
		printf("%d\n",ans_chu);
	}
    return 0;
}
//F**k CCF!!!!!
/*
//a1~ap-1放到两个人的中间
		for(int i=1;i<=p-1;i++){
			q.push(a[i]);
		}
		//边放边取 
		for(int i=p;i<=n-1;i++){
			q.push(a[i]);
			if(i&1){//奇数：出题人 
				ans_chu+=q.top();
				q.pop();
			}else{
				ans_zuo+=q.top();
				q.pop();
			}
		}
		//第n个：
		q.push(a[n]);
		if((n-p)&1) ans_zuo+=q.top();//奇数：A做题人，B出题人 
		else ans_chu+=q.top();//偶数：A出题人，B做题人 
		q.pop();
		for(int i=(n-p)&1+1;!q.empty();i++){
			if(i&1){//做题人 
				ans_zuo+=q.top();
			}else{//出题人 
				ans_chu+=q.top(); 
			}
			q.pop();
		}
		printf("---%d\n",ans_chu);
*/
