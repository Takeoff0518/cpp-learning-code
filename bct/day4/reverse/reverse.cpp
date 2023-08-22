#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1000005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int k,n,b[N];
char s[N],res[N];
struct node{
	int l,r,num,rev;
}nd[N],tr[N];
int main(){
//	freopen("reverse.in","r",stdin);
//	freopen("reverse.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&b[i]);
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		cnt++;
		nd[cnt].l=b[i-1]+1,
		nd[cnt].r=b[i],
		nd[cnt].num=cnt;
	}
	int nowl=1,nowr=cnt,now=1;
	for(int i=cnt;i>=1;i--){
		if(now&1){
			tr[nowl]=nd[i],
			tr[nowl].rev=now,
			++nowl;
		}else{
			tr[nowr]=nd[i],
			tr[nowr].rev=now,
			--nowr;
		}
		now^=1;
	}
	int p1=0;
	for(int i=1;i<=cnt;i++){
		if(tr[i].rev){
			for(int j=tr[i].r;j>=tr[i].l;j--){
				res[++p1]=s[j];
			}
		}else{
			for(int j=tr[i].l;j<=tr[i].r;j++){
				res[++p1]=s[j];
			}
		}
	}
	for(int i=b[k]+1;i<=n;i++)
		res[++p1]=s[i];
	printf("%s\n",res+1);
	return 0;
}

