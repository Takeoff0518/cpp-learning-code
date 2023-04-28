#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define PII pair<int,int>
const int N=200005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m;
struct node{
	int a,b;
	bool operator < (const node &x) const{
		return x.b<b; 
	}
}s[N];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i].a);
		s[i].b=s[i].a%m;
	}
	sort(s+1,s+n+1);
	
    return 0;
}
//F**k CCF!!!!!

