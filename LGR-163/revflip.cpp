#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (2000005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
ll read(){
    char ch=getchar(); ll x=0,f=1;
    while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar();}
    while('0'<=ch&&ch<='9'){ x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
int n;
bool a[N],b[N];
int loc[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) a[i]=read();
    if(n&1){ // odd
    	int cnt=0;
		for(int i=n;i>=1;i-=2) loc[++cnt]=i;
		for(int i=2;i<=n-1;i+=2) loc[++cnt]=i; 
	}else{
		int cnt=0;
		for(int i=n;i>=2;i-=2) loc[++cnt]=i;
		for(int i=1;i<=n-1;i+=2) loc[++cnt]=i;
	}
//	for(int i=1;i<=n;i++){
//		printf("%d ",loc[i]);
//	}
//	puts("");
	for(int i=1;i<=n;i++){
//		printf("%d-\n",t-loc[i]); 
		b[i]=a[loc[i]];
		b[i]^=(n+1-loc[i])&1;
//		if((t-loc[i])&1) b[i]=!b[i],puts("z");
	}
	for(int i=1;i<=n;i++){
		printf("%d ",b[i]);
	}
	puts("");
    return 0;
}
/*
1:1 
1 
2:2 1 
1 2 
3:3 1 2 
1 3 2 
4:4 2 1 3 
1 3 4 2 
5:5 3 1 2 4 
1 3 5 4 2 
6:6 4 2 1 3 5 
1 3 5 6 4 2 
7:7 5 3 1 2 4 6 
1 3 5 7 6 4 2 
8:8 6 4 2 1 3 5 7 
1 3 5 7 8 6 4 2 
9:9 7 5 3 1 2 4 6 8 
1 3 5 7 9 8 6 4 2 
10:10 8 6 4 2 1 3 5 7 9 
1 3 5 7 9 10 8 6 4 2 
11:11 9 7 5 3 1 2 4 6 8 10 
1 3 5 7 9 11 10 8 6 4 2 
12:12 10 8 6 4 2 1 3 5 7 9 11 
1 3 5 7 9 11 12 10 8 6 4 2 
13:13 11 9 7 5 3 1 2 4 6 8 10 12 
1 3 5 7 9 11 13 12 10 8 6 4 2 
14:14 12 10 8 6 4 2 1 3 5 7 9 11 13 
1 3 5 7 9 11 13 14 12 10 8 6 4 2 
15:15 13 11 9 7 5 3 1 2 4 6 8 10 12 14 
1 3 5 7 9 11 13 15 14 12 10 8 6 4 2 
16:16 14 12 10 8 6 4 2 1 3 5 7 9 11 13 15 
1 3 5 7 9 11 13 15 16 14 12 10 8 6 4 2 
17:17 15 13 11 9 7 5 3 1 2 4 6 8 10 12 14 16 
1 3 5 7 9 11 13 15 17 16 14 12 10 8 6 4 2 
18:18 16 14 12 10 8 6 4 2 1 3 5 7 9 11 13 15 17 
1 3 5 7 9 11 13 15 17 18 16 14 12 10 8 6 4 2 
19:19 17 15 13 11 9 7 5 3 1 2 4 6 8 10 12 14 16 18 
1 3 5 7 9 11 13 15 17 19 18 16 14 12 10 8 6 4 2 
20:20 18 16 14 12 10 8 6 4 2 1 3 5 7 9 11 13 15 17 19 
1 3 5 7 9 11 13 15 17 19 20 18 16 14 12 10 8 6 4 2 

*/
