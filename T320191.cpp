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
int t;
ll x,y;
int main(){
    cin>>t;
    while(t--){
        cin>>x>>y;
        while(1){
            //x操作
            if(x>=y) x/=2;
            else if(x<y) x++;
            // cout<<x<<' '<<y<<endl;
            if(x==0 || y==0) break;
            //y操作
            if(y>=x) y/=2;
            else if(y<x) y++;
            // cout<<x<<' '<<y<<endl;
            if(x==0 || y==0) break;
        }
        cout<<x<<' '<<y<<endl;
    }
    return 0;
}