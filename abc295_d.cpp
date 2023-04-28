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
string s;
int n;
ll now,ans;
map<ll,ll> f;
int main(){
    cin>>s;
    n=s.size();
    f[0]=1;
    for(int i=0;i<n;i++){
        int t=s[i]-'0';
        now^=1<<t;
        ans+=f[now]; f[now]++;
    }
    cout<<ans<<endl;
    return 0;
}