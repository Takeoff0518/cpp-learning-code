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
ll x;
string s;
bool a,b,c;
int main(){
    cin>>x>>s;
    if(s[0]=='A' || s[1]=='A') a=1;
    if(s[0]=='B' || s[1]=='B') b=1;
    if(s[0]=='C' || s[1]=='C') c=1;
    if (b && c) cout<<x*6/10; 
    else if(b) cout<<x*8/10;
    else if(c) cout<<x*7/10;
    else cout<<x<<endl;
    // else if (b && c) cout<<x*6/10; 
    return 0;
}