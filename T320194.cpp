#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (100005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
ll n,a[N],b[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
        // cout<<a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        b[i]+=b[i-1];
    }
    for(int i=1;i<=n;i++){
        if(a[i]<b[i]){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}