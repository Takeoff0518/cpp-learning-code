#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
string s;
int ans;
int main(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z'){
            ans=i+1;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}