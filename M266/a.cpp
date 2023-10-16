#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (100005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,ans=INF;
int a[N],b[N];
int ran[N];
int score[N];
void get_rank(){
	for(int i=1;i<=n;i++){
		ran[i]=1+a[i];
	}
}
int check(){
	int liar=0;
	for(int i=1;i<=n;i++){
		if(a[i]+b[i]+1>n) liar++;
		else if(ran[i]!=score[i]){
			liar++;
		}
	} 
	return liar;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d",&a[i],&b[i]);
	for(int i=1;i<=n;i++) score[i]=i;
	get_rank();
	do{
		ans=min(ans,check());
	}while(next_permutation(score+1,score+n+1));
	printf("%d\n",ans); 
    return 0;
}

