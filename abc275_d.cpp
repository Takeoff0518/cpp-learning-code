#include<iostream>
#include<map>
#define ll long long
using namespace std;
ll n;
map<ll,ll> f;//记忆化搜索数组 
ll fun(ll x){
	if(f[x]) return f[x];
	if(x==0) return 1;
	f[x]=fun(x/2)+fun(x/3);
	return f[x];
}
int main(){
	cin>>n;
	cout<<fun(n);
    return 0;
}
//F**k CCF!!!!!

