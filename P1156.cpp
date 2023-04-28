#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int d,g;
int dp[N][N];
int ans=-INF;
struct node{
    int t,v,h;
    bool operator < (const node &x) const{
        return x.t>t;
    }
}a[N];
#define t(xxx) a[xxx].t
#define v(xxx) a[xxx].v
#define h(xxx) a[xxx].h
int main(){
    scanf("%d %d",&d,&g);
    for(int i=1;i<=g;i++){
        scanf("%d %d %d",&t(i),&v(i),&h(i));
    }
    sort(a+1,a+g+1);
    memset(dp,~0x3f,sizeof(dp));
    dp[0][0]=10;
    t(0)=0;
    for(int i=1;i<=g;i++){
        for(int j=d;j>=0;j--){
            if(dp[i-1][j]<t(i)-t(i-1)){
                continue;
            }
            if(j+h(i)>=d){
                printf("%d\n",t(i));
                return 0;
            }
            dp[i][j+h(i)]=max(dp[i][j+h(i)],dp[i-1][j]-(t(i)-t(i-1)));
            dp[i][j]=max(dp[i][j],dp[i-1][j]+v(i)-(t(i)-t(i-1)));
        }
        ans=max(ans,dp[i][0]+t(i));
    }
    printf("%d\n",ans);
    return 0;
}