#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
#define abs(xxx) (xxx)>=0 ? (xxx) : -(xxx)
using namespace std;
int x1,x2,y1,y2;
int x,y,ans;
int li[5][5]={{0,3,2,3,2},
              {3,2,1,2,3},
              {2,1,4,3,2},
              {3,2,3,2,3},
              {2,3,2,3,4}};
int main(){
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    x=max(abs(x1-x2),abs(y1-y2));
    y=min(abs(x1-x2),abs(y1-y2));
    while(x>4 || y>4){
        if(x<0) x=-x;
        if(y<0) y=-y;
        if(x<y) swap(x,y);
        x-=2,y-=1;
        ans++;
    }
    printf("%d\n",ans+li[x][y]);
    return 0;
}