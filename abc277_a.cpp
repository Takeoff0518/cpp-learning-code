#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define PII pair<int,int>
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,x,a[N],loc;

int main(){
	scanf("%d %d",&n,&x);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==x) loc=i;
	}
	printf("%d\n",loc);
    return 0;
}
//F**k CCF!!!!!

