#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 1000005
#define M 10005
using namespace std;
int n,a[N];
int re(int l,int r){
    int maxx=-INF;
    for(int i=l;i<=r;i++){
        maxx=max(maxx,a[i]);
    }
    return maxx;
}
ll ans=0;
int main(){
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans+=re(i,j);
        }
    }
    printf("%d\n",ans);
    return 0;
}