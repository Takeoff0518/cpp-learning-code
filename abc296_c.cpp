#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#define N (200005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,x,a[N];
map<ll,bool> mp;
int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(x==0){
        puts("Yes");
        return 0;
    }
    else if(x>0){
        for(int i=1;i<=n;i++){
            mp[a[i]]=1;
            if(mp[a[i]-x]){
                puts("Yes");
                return 0;
            }
        }
    }else{
        for(int i=n;i>=1;i--){
            mp[a[i]]=1;
            if(mp[a[i]-x]){
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}