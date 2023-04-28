#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (5005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,f[N],ans=-1;
struct node{
    int l,w;
    bool operator < (const node &x) const{
        return l==x.l ? w>x.w : l>x.l;
    }
}a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].l,&a[i].w);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(a[j].w<a[i].w)
                f[i]=max(f[j]+1,f[i]);
        }
        ans=max(ans,f[i]);
    }
    printf("%d\n",ans+1);
    return 0;
}