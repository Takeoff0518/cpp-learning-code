#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define INF 0x3f3f3f3f
#define N 200005
using namespace std;
int n,m,s,t;
ll a[N];
ll s1[N],s2[N];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    s1[1]=0;
    for(int i=2;i<=n;i++){
        s1[i]=s1[i-1];
        if(a[i-1]>a[i]){
            s1[i]+=a[i-1]-a[i];
        }
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d ",s1[i]);
    // }
    // puts("");
    for(int i=n-1;i>=1;i--){
        s2[i]=s2[i+1];
        if(a[i]<a[i+1]){
            s2[i]+=a[i+1]-a[i];
        } 
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d ",s2[i]);
    // }
    // puts("");

    for(int i=1;i<=m;i++){
        scanf("%d %d",&s,&t);
        if(s<t){
            printf("%lld\n",s1[t]-s1[s]);
        }else{
            printf("%lld\n",s2[t]-s2[s]);
        }
    }
    // fclose(stdin);
    // fclose(stdout);
    // printf("%lld\n",(clock()-s1)/1000);
    return 0;
}