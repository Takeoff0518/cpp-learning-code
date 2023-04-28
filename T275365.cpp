#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 10005
#define M 10005
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    while(n--){
        ll l,r;
        scanf("%lld %lld",&l,&r);
        if(l==r){
            printf("%lld\n",(l&1));
        }else{
            if(!(l&1)){
                l++;
            }
            if(!(r&1)){
                r--;
            }
            //printf("%d %d,",l,r);
            printf("%lld\n",((r-l)>>1)+1);
        }
    }
    return 0;
}