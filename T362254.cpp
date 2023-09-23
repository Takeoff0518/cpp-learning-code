#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (5005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,k,m;
int a[N],b[N],c[N];
int main(){
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){ cin>>b[i]; c[i]=c[i-1]+a[i]-b[i];}
    for(int i=k;i<=n;i++){
        //l=i-k+1 r=i
        if(c[i]-c[i-k]>=m){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}