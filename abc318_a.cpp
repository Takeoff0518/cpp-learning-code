#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m,p;
int main(){
    scanf("%d %d %d",&n,&m,&p);
    int ans=0;
    for(int i=m;i<=n;i+=p){
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}