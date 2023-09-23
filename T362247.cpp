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
int k,a,b,c;
int s[N];
int main(){
    cin>>k>>a>>b>>c;
    for(int i=1;i<=k;i++){
        cin>>s[i];
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        int tmp=0;
        if(s[i]<=10){
            tmp+=s[i]*a;
        }else if(s[i]>10 && s[i]<=100){
            tmp+=10*a+(s[i]-10)*b;
        }else{
            tmp+=10*a+90*b+(s[i]-100)*c;
        }
        ans+=tmp;
        // cout<<tmp<<endl;
    } 
    cout<<ans<<endl;
    return 0;
}