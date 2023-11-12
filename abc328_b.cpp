#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n;
int a[N];
bool check(int x){
	int pre=x%10;
	x/=10;
	while(x){
		if(x%10!=pre) return 0;
		x/=10;
	}
	return 1;
}
int ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++){
		if(!check(i)) continue;
		for(int j=1;j<=a[i];j++){
			if(check(j) && i%10==j%10){
//				cout<<i<<' '<<j<<endl;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}
/*
	zyb txdy!
	Author: takeoff37808
*/

