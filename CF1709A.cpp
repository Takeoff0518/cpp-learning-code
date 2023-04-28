#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 10005
#define M 10005
using namespace std;
int t,x,a[4],b[4];
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>x>>a[1]>>a[2]>>a[3];
        if(a[x]==0){
            cout<<"NO"<<endl;
        }else if(a[a[x]]==0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}