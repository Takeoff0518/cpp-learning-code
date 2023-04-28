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
char a[N];
int main(){
    cin>>a+1;
    int n=strlen(a+1);
    for(int i=1;i<=n;i+=2){
        swap(a[i],a[i+1]);
    }
    cout<<a+1<<endl;
    return 0;
}