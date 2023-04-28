#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int main(){
    ll n;
    cin>>n;
    if(n%2==0){
        cout<<n/2<<endl;
    }else{
        cout<<-n/2-1<<endl;
    }
    return 0;
}