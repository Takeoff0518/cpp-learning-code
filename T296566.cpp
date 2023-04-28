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
int n,x[N],y[N];
int ex,ey;
int ans=0,minn=INF;
int main(){
    scanf("%d %d %d",&n,&ex,&ey);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x[i],&y[i]);
    }
    for(int i=1;i<=n;i++){
        ans+=min({
            abs(ex-(x[i]+(i-1)))+abs(ey-y[i]), //右上角近
            abs(ex-x[i])+abs(ey-y[i]), //左上角近
            abs(ex-x[i])+abs(ey-(y[i]-(i-1))), //左下角近
            abs(ex-(x[i]+(i-1)))+abs(ey-(y[i]-(i-1))) //右下角近
        });
    }
    printf("%d",ans);
    return 0;
}