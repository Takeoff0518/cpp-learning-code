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
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    if(n<1000) n=1000;
    for(int i=n;i<=m;i++){
        int tmp=i,sum=0;
        while(tmp){
            sum+=(tmp%10)*(tmp%10)*(tmp%10)*(tmp%10);
            tmp/=10;
        }
        if(sum==i) printf("%d\n",i);
    }
    return 0;
}