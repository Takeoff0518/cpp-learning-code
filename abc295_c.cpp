#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,ans;
map<int,int> mp;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1,t;i<=n;i++){
        cin>>t;
        if(mp[t]==1){
            ans++;
            // cout<<":"<<t<<endl;
            mp[t]=0;
        }else mp[t]++;
    }
    cout<<ans<<endl;
    return 0;
