#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (200005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N];
bool b[N];
int cnt,ans[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!b[i]) b[a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(!b[i]) ans[++cnt]=i;
    }
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++){
        cout<<ans[i]<<' ';
    }

    return 0;
}