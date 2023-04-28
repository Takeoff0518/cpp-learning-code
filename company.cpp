#include<iostream>
#include<cstdio>
#define N 500005
#define int long long
using namespace std;
int n,a[N];
int money[N];
bool away[N];
int ans=0;
void findfa(int x,int t){
    money[x]+=t;
    if(x!=a[x])
        findfa(a[x],t+1);
}
signed main(){
    // freopen("company.in","r",stdin);
    // freopen("company.out","w",stdout);
    scanf("%lld",&n);
    a[1]=1;
    for(int i=2;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=n;i>=0;i--){
        if(!away[i]){
            away[i]=1;
            findfa(i,1);
        }
    }
    for(int i=1;i<=n;i++){
        printf("%lld ",money[i]);
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}