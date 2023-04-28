#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define abs(xxx) ((xxx)>0 ? (xxx) : -(xxx))
const int N=1005,M=512;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
string a[N],ans[N],now[N];
bool vis[N],f=0;
int n,len[N],sum=0;
int s1[M],s2[M];
void dfs(int last,int step){
	if(f==1) return;
	if(step==n){
		f=1;
		for(int i=1;i<=sum;i++)
			ans[i]=now[i];
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		if(a[last][a[last].size()-1]==a[i][0]){
			now[++sum]=a[i],vis[i]=1;
			dfs(i,step+1);
			sum--,vis[i]=0;
		}
	}
}
int main(){
	//ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		len[i]=a[i].size();
		s1[a[i][0]]++;
		s2[a[i][len[i]-1]]++;
	}
	char s,t;
	for(char c='a';c<='z';c++){
		if(s1[c]-s2[c]==1) s=c;
		else if(s2[c]-s1[c]==1) t=c;
	}
	int cnt=s2[t],start=1;
	for(int i=1;i<=n;i++){
		if(a[i][0]==s && (a[i][len[i]-1]!=t || cnt!=1)){
			start=i;
			break;
		}
	}
	vis[start]=1,now[++sum]=a[start];
	dfs(start,1);
	if(!f){
		cout<<"***"<<endl;
	}else{
		for(int i=1;i<=n;i++){
			if(i!=n) cout<<ans[i]<<'.';
			else cout<<ans[i]<<endl;
		}
	}
	
    return 0;
}
//F**k CCF!!!!!

