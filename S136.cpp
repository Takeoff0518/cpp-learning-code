#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=300005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m;
ll a[N],s[N],k;
int main(){
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%lld",&s[i]);
    }
    scanf("%d",&n);
    for(int t=1;t<=n;t++){
        // memset(a,0,sizeof(a));
        scanf("%lld %lld %lld",&a[0],&a[1],&n);
        for(int i=2;i<=20;i++){
            a[i]=1LL*n*a[i-1]+a[i-2];
            // printf("%lld ",a[i]);
        }
        // puts("");
        ll min_si=0,max_si=0,minn=INF,maxx=-INF;
        for(int i=1;i<=m;i++){
            ll a_si=a[s[i]];
            if(s[i]>20){
                continue;
            }
            if(minn>a_si){
                // printf("min:%lld->%lld\n",minn,a_si);
                minn=a_si;
                min_si=s[i];
            }
            if(maxx<a_si){
                // printf("max:%lld->%lld\n",maxx,a_si);
                maxx=a_si;
                max_si=s[i];
            }
        }
        bool ou_zheng=1,ou_fu=1,upper=1,lower=1;
        for(int i=11;i<=20;i++){
            if(a[i-1]<a[i]){
                lower=0;
            }
            if(a[i-1]<a[i]){
                upper=0;
            }
            if(!(i&1) && a[i]<0){
                ou_zheng=0;
            }
            if(!(i&1) && a[i]>0){
                ou_fu=0;
            }
        }
        if(s[m]>30){
            if(upper){
                max_si=upper;
            }else if(lower){
                min_si=lower;
            }else if(ou_zheng){
                for(int i=m;i>=0;i--){
                    if(!(s[i]&1)){
                        max_si=s[i];
                        break;
                    }
                }
                for(int i=m;i>=0;i--){
                    if(s[i]&1){
                        min_si=s[i];
                        break;
                    }
                }
            }else if(ou_fu){
                for(int i=m;i>=30;i--){
                    if(!(s[i]&1)){
                        min_si=s[i];
                        break;
                    }
                }
                for(int i=m;i>=30;i--){
                    if(s[i]&1){
                        max_si=s[i];
                        break;
                    }
                }
            }
        }
        printf("%d %d\n",max_si,min_si);
    }
    return 0;
}