#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N],sum;
double ans;
bool f[N][N];
double calc(double x,double y,double z){
    double p=(x+y+z)/2;
    return sqrt(p*(p-x)*(p-y)*(p-z));
}
bool check(int x,int y,int z){
    if(x+y>z && x+z>y && y+z>x) return 1;
    else return 0;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    f[0][0]=1;
    for(int k=1;k<=n;k++){
        for(int i=sum/2;i>=0;i--){
            for(int j=sum/2;j>=0;j--){
                if(i-a[k]>=0 && f[i-a[k]][j]) f[i][j]=1;
                if(j-a[k]>=0 && f[i][j-a[k]]) f[i][j]=1;
            }
        }
    }
    ans=-1;
    for(int i=sum/2;i>0;i--){
        for(int j=sum/2;j>0;j--){
            if(!f[i][j]) continue;
            if(!check(i,j,sum-i-j)) continue;
            ans=max(ans,calc(i,j,sum-i-j));
        }
    }
    if(ans!=-1) cout<<(ll)(ans*100)<<endl;
    else cout<<ans<<endl;
    
    return 0;
}