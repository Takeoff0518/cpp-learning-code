#include <iostream>
#define ll long long
#define ull unsigned long long
using namespace std;
int a[65];
ull binpow(ull a,ull b){
    ull res=1;
    while(b>0){
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main(){
    ull n,k;
    cin>>n>>k;
    k++;
    ull n1=binpow(2,n-2);
    bool flag=0;
    while(n1){
        if(flag==0){
            if(k<=n1){
                flag=0;
                cout<<"0";
            }
            else{
                flag=1;
                k-=n1;
                cout<<"1";
            }
            
        }else{
            if(k<=n1){
                flag=0;
                cout<<"1";
            }else{
                cout<<"0";
                k-=n1;
                flag=1;
            }
        }
        n1/=2;
    }
    return 0;
}
