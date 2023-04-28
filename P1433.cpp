#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define INF 0x3f3f3f3f
#define ll long long
#define N 20
#define M 10005
#define dist(_x1_,_y1_,_x2_,_y2_)\
        sqrt((_x1_-_x2_)*(_x1_-_x2_)+(_y1_-_y2_)*(_y1_-_y2_))
#define lowbit(_x_)\
        _x_&(-_x_)
using namespace std;
int n;
double x[N],y[N],dis[N][N],dp[65000][20];
int idx[N];
bool vis[N];
double ans=1e18;
void dfs(int x,double now,int from,int b){
    if(x==n+1){
        //printf("%.3lf\n",now);
        if(ans>now){
            ans=now;
        }
        return;
    }
    if(now>=ans){
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int p=b+(1<<(i-1));
            if(dp[p][i]!=0 && dp[p][i]<=now+dis[from][i]){
            	continue;
			}
			vis[i]=1;
			dp[p][i]=now+dis[from][i];
			dfs(x+1,dp[p][i],i,p);
			vis[i]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf %lf",&x[i],&y[i]);
    }
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dis[i][j]=dis[j][i]=dist(x[i],y[i],x[j],y[j]);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         printf("%.2lf ",dis[i][j]);
    //     }
    //     puts("");
    // }
    dfs(1,0.0,0,0);
    printf("%.2lf",ans);
    return 0;
}
