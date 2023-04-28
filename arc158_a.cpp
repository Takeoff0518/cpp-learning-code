#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define ull unsigned long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
#define abs(xxx) ((xxx)>=0 ? (xxx) : -(xxx))
using namespace std;
ll t,a[3];
int main(){
    // ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>a[0]>>a[1]>>a[2];
        // if(a[0]>a[1]) swap(a[0],a[1]);
        // if(a[1]>a[2]) swap(a[1],a[2]);
        // a[2]-=a[0]; a[1]-=a[0]; a[0]=0;
        if((a[0]+a[1]+a[2])%3!=0 || abs(a[0]-a[1])%2!=0 || abs(a[0]-a[2])%2!=0 || abs(a[1]-a[2])%2!=0){
            cout<<-1<<endl;
            continue;
        }else{
            ll maxx=max({a[0],a[1],a[2]}),ans=0,d;
            a[0]=abs(a[0]-maxx);
            a[1]=abs(a[1]-maxx);
            a[2]=abs(a[2]-maxx);
            d=(a[0]+a[1]+a[2])/3;
            if(a[0]>=d) ans+=(a[0]-d)/2;
            if(a[1]>=d) ans+=(a[1]-d)/2;
            if(a[2]>=d) ans+=(a[2]-d)/2;
            cout<<ans<<endl;
        }
    }
    return 0;
}