#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll unsigned long long
#define Q 0
#define L 1
#define R 2
#define P 3
#define lson(xxx) (xxx)<<1
#define rson(xxx) (xxx)<<1|1
const int N=40005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
char t[N];
int tree[N],n;
int qpos[N],cnt; 
ll ans;
int a[N],b[N];
ll check(){
	ll cnt=0;
	ll pos=1;
	for(int i=1;i<=n;i++){
		if(t[i]=='L'){
			pos=lson(i);
		}else if(t[i]=='R'){
			pos=rson(pos);
		}	
//		}else if(t[i]=='P' && t[i-1]!='P'){
//			cnt+=pos;
//			//cout<<pos<<' ';
//		}
	}
	//cout<<endl;
	cnt+=pos;
	//cout<<cnt<<endl;
	return cnt; 
}
void dfs(int x){
	if(x==cnt+1){
//		for(int i=1;i<=n;i++){
//			cout<<t[i];
//		}
//		cout<<endl;
		ans+=check();
		return;
	}
	t[qpos[x]]='L';
	dfs(x+1);
	t[qpos[x]]='R';
	dfs(x+1);
	t[qpos[x]]='P';
	dfs(x+1);
}
int main(){
	cin>>t+1;
	n=strlen(t+1);
	for(int i=1;i<=n;i++){
		if(t[i]=='*'){
			qpos[++cnt]=i;
		}
	}
	dfs(1);
	cout<<ans<<endl;
    return 0;
}

