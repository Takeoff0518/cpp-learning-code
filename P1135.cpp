#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,a,b,k[N],dis[N];
queue<int> q;
bool vis[N],f=1;
void bfs(int x){
	q.push(x);
	while(!q.empty()){
		int xx=q.front();
		q.pop();
		if(xx==b){
			printf("%d\n",dis[b]);
			f=0;
			return;
		}
		if(xx+n[xx]<=n && xx+n[xx]>=1 && !vis[xx+n[xx]]){
			dis[xx+n[xx]]=dis[xx]+1;
			q.push(xx+n[xx]);
			vis[xx+n[xx]]=1;
		}
		if(xx-n[xx]<=n && xx-n[xx]>=1 && !vis[xx-n[xx]]){
			dis[xx-n[xx]]=dis[xx]+1;
			q.push(xx-n[xx]);
			vis[xx-n[xx]]=1;
		}
	}
}
int main(){
	scanf("%d %d %d",&n,&a,&b);
	for(int i=1;i<=n;i++){
		scanf("%d",&n[i]);
	}
	bfs(a);
	if(f){
		puts("-1"); 
	}
    return 0;
}

