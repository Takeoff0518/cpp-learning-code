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
double a,b,c,d;
int main(){
    cin>>a>>b>>c>>d;
    double tot=1.0*a*b+1.0*c*d;
    printf("%.1lf",tot);
    printf("\n%.1lf",tot/(b+d));
    return 0;
}