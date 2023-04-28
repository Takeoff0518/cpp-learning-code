#include<iostream>
#include<bitset>
#include<cstdio>
#define N 1005
#define mod 1000000000
#define ull unsigned long long
using namespace std;
int n,m;
ull a[N],b[N];
bitset<10010>t;
inline ull gcd(ull x,ull y){
    while(x^=y^=x^=y%=x);
    return y;
}
ull ans_a=1,ans_b=1;
bool f=0;
int main(){
    // freopen("gcd.in","r",stdin);
    // freopen("gcd.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
       scanf("%lld",&b[i]);
    }
    for(int i=1;i<=n;i++){
        a[i]%=mod;
        ans_a*=a[i];
        if(ans_a>=mod){
            f=1;
        }
        ans_a%=mod;
        //cout<<ans_a<<' ';
    }
    //puts("");
    for(int i=1;i<=m;i++){
        b[i]%=mod;
        ans_b*=b[i];
        if(ans_b>=mod){
            f=1;
        }
        ans_b%=mod;
        //cout<<ans_b<<' ';
    }
    //cout<<ans_a<<' '<<ans_b<<endl;
    printf("%lld",gcd(ans_a,ans_b));
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}