#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=100005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int t,n;
int son[N][12],cnt[N],idx;
char s[20];
bool vis[N],f;
void init(){
	f=1,idx=1;
	memset(son,0,sizeof(son));
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
}
void ins(char str[]){
	int p=1,len=strlen(str);
	for(int i=0;str[i];i++){
		int u=str[i]-'0'+1;
		if(!son[p][u]) son[p][u]=++idx,vis[p]=1;
		if(cnt[p]){
			f=0;
			return;
		}
		p=son[p][u];
	}
	if(vis[p]) f=0;
	cnt[p]++;
}
int main(){
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			if(f) ins(s);
		}
		if(f) puts("YES");
		else puts("NO");
	}
    return 0;
}
//F**k CCF!!!!!
