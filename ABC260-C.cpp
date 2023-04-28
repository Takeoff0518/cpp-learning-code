#include<iostream>
#include<cstdio>
#include<cstring>
#define blue 1
#define red 0
#define ll long long
using namespace std;
ll n,x,y;
ll ans=0;
ll f[20][20][4];
void fun(ll amount,ll level,bool kind){
    //printf("amount=%lld,level=%lld,kind=%s\n",amount,level,kind==blue ? "blue" : "red");
    ll anstmp=ans;
    if(level<2){
        if(kind==blue){
            ans+=amount;
            //printf("oops!\n");
        }
        return;
    }
    if(f[amount][level][kind]!=-1){
        ans+=f[amount][level][kind];
        return;
    }
    if(kind==red){
        for(int i=1;i<=amount;i++){
            fun(1,level-1,red);
            fun(x,level,blue);
        }
    }else if(kind==blue){
        for(int i=1;i<=amount;i++){
            fun(1,level-1,red);
            fun(y,level-1,blue);
        }
    }
    f[amount][level][kind]=ans-anstmp;
}
int main(){
    cin>>n>>x>>y;
    memset(f,~0,sizeof(f));
    fun(1,n,red);
    cout<<ans;
    return 0;
}