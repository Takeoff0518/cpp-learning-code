#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (105)
#define M (100005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int l,s,t,m,ans=INF;
int a[N],f[M],b[N];
bool tong[M];
const int eps=1000;

int main(){
    scanf("%d %d %d %d",&l,&s,&t,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
        // tong[a[i]]=1;
    }
    a[m+1]=l;
    sort(a+1,a+m+2);
    if(s==t){
        int sum=0;
        for(int i=1;i<=m;i++)
            if(a[i]%s==0) sum++;
        printf("%d\n",sum);
        return 0;
    }
    memset(f,0x3f,sizeof(f)); f[0]=0;
    for(int i=1;i<=m;i++){
        if(a[i]-a[i-1]>eps) b[i]=b[i-1]+eps;
        else b[i]=a[i]-a[i-1]+b[i-1];
    }
    for(int i=1;i<=m;i++)
        tong[b[i]]=1;
    l=b[m];
    for(int i=1;i<=l+t-1;i++){
        f[i]=INF;
        for(int j=s;j<=t && j<=i;j++)
            f[i]=min(f[i],f[i-j]);
        if(tong[i]) f[i]++;
    }
    int ans=f[l];
    for(int i=l;i<=l+t-1;i++)
        ans=min(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}