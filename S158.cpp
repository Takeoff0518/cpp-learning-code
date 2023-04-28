#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime> 
#define ll unsigned long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=1e9+9;
using namespace std;
int now;
int n,m,n;
int a[N],b[N];
int numa[N],numb[N];
ll ans=0;
//int t[N];
void check(){
	for(int i=1;i<=n;i++){
		if(numa[i]<=numb[i]){
			return;
		}
	}
	ans++;
	ans%=p;
}
void dfsb(int x,int now){
	//cout<<"dfsb:"<<x<<' '<<now<<endl;
	if(x>=m+1 && now<n+1){
		return;
	}
	if(now>=n+1){
		check();
		return;
	}
	numb[now]=b[x];
	dfsb(x+1,now+1);//ѡ
	dfsb(x+1,now);//��ѡ 
}
void dfsa(int x,int now){
	//cout<<"dfsa:"<<x<<' '<<now<<endl;
	if(x==n+1 && now!=n+1){
		return;
	}
	if(now>=n+1){
		dfsb(1,1);
		return;
	}
	numa[now]=a[x];
	dfsa(x+1,now+1);//ѡ
	dfsa(x+1,now);//��ѡ 
}

int main(){
	a[0]=b[0]=-1; 
	scanf("%d %d %d",&n,&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	dfsa(1,1);
	cout<<ans<<endl;
    return 0;
}

