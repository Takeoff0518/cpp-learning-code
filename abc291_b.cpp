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
using namespace std;
int a[N],n;
double sum;
int main(){
    cin>>n;
    for(int i=1;i<=n*5;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*5+1);
    for(int i=n+1;i<=n*4;i++)
        sum+=(double)a[i];
    printf("%.15lf",sum/(1.0*n*3));
    return 0;
}