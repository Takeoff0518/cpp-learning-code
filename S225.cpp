#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1000005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int a[N],n,maxx=-INF;
ll ans_price,ans_sum=-INF,sum;
int main(){
    scanf("%d",&n);
    for(int i=1,t;i<=n;i++){
        scanf("%d",&t);
        a[t]++;
        // sum+=t;
        maxx=max(maxx,t);
    }
    sum=n;
    for(int i=0;i<=maxx;i++){
        ll tmp=1LL*sum*i;
        if(tmp>ans_sum){
            ans_price=i;
            ans_sum=tmp;
        }
        sum-=a[i];
        // printf("i=%d,sum=%d,tmp=%d\n",i,sum,tmp);
    }
    printf("%lld %lld\n",ans_sum,ans_price);
    return 0;
}