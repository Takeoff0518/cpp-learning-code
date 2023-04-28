#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 1000005
#define M 10005
using namespace std;
int n;
int a[N],c[N],x;
int ans;
inline int labs(int t){
    return t>=0 ? t : -t;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        x+=a[i];
    }
    x/=n;
    for(int i=1;i<=n;i++){
        a[i]-=x;
    }
    for(int i=1;i<=n;i++){
        c[i]=c[i-1]-a[i-1];
    }
    sort(c+1,c+n+1);
    int mid=c[(n+1)/2];
    for(int i=1;i<=n;i++){
        ans+=labs(mid-c[i]);
    }
    printf("%d\n",ans);
    return 0;
}