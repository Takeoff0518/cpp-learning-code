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
int n,a[N],k,cnt;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1+k;i<=n;i++){
		cnt++;
		cout<<a[i]<<' ';
	}
	for(int i=1;i<=n-cnt;i++){
		cout<<0<<' ';
	}
	cout<<endl;
    return 0;
}
//F**k CCF!!!!!

