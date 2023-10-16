#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define ll long long
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int a[N],b[N];
void fun(int n){
//	int n=20;
	cout<<n<<':';
	for(int i=1;i<=n;i++) a[i]=i,b[i]=0;
	for(int i=1;i<=n;i++){
		reverse(a+1,a+i+1);
		reverse(b+1,b+i+1);
		for(int j=1;j<=i;j++) b[j]++;
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<b[i]<<' ';
	}
	cout<<endl;
}
int main(){
	for(int i=1;i<=20;i++){
		fun(i);
	}
    return 0;
}
//F**k CCF!!!!!

