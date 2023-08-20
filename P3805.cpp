#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (30000005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
char ts[N],s[N];
int n,m,p[N];
int main(){
    scanf("%s",ts+1);
    n=strlen(ts+1);
    // #A#B#C#C#B#A#
    s[++m]='#';
    for(int i=1;i<=n;i++){
    	s[++m]=ts[i];
    	s[++m]='#';
	}
	/*
	j为i以mid为中心的对称点 
	(i+j)/2=mid
	i+j=mid*2
	j=mid*2-i
	*/
	// p[i]: 以i为对称中心，能拓展的回文数量 
	int mid=0,maxr=0;
	for(int i=1;i<=m;i++){
		int j=(mid<<1)-i;
		// case1: mid<i<maxr 
		if(mid<=i && i<=maxr)
			p[i]=min(p[j],maxr-i+1);
		else p[i]=1; 
		// case2: i>maxr
		// 暴力拓展 
		while(i-p[i]>=1 && s[i-p[i]]==s[i+p[i]])
			p[i]++;
		if(i+p[i]-1>maxr){
			maxr=i+p[i]-1;
			mid=i;
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		ans=max(ans,p[i]-1);
	}
	printf("%d\n",ans);
    return 0;
}
