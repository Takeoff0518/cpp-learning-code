#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define N (3005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N],b[N];
/*警钟敲烂： 
3. 任务i(0<i<=n)可以被处理
当且仅当每个任务j(j<i)已经
被完成或者正在进行。
max(ta,tb)
*/
int dfs(int x,int ta,int tb){
	if(x==n+1){
		return max(ta,tb);
	}
	return min(
		dfs(x+1,ta+a[x],max(ta,tb)),
		dfs(x+1,max(ta,tb),tb+b[x])
	);
}
int main(){
	freopen("task.in","r",stdin);
	freopen("task.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d",&a[i],&b[i]);
	printf("%d\n",dfs(1,0,0));
    return 0;
}

