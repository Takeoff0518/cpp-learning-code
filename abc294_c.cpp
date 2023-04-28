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
int n,m;
struct node{
    int v,q;
    bool operator < (const node &x) const{
        return x.v>v;
    }
}s[N];
int a[N],b[N],cnta,cntb;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i].v;
        s[i].q=1;
    }
    for(int i=n+1;i<=n+m;i++){
        cin>>s[i].v;
        s[i].q=2;
    }
    sort(s+1,s+n+m+1);
    for(int i=1;i<=n+m;i++){
        if(s[i].q==1){
            a[++cnta]=i;
        }else b[++cntb]=i;
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    cout<<endl;
    return 0;
}