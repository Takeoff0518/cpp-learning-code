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
ll x1,y1,x2,y2;
ll ex,ey;
ll step;
inline ll aabs(ll x){
    return x>0 ? x : -x;
}
int main(){
    cin>>x1>>y1>>x2>>y2;
    ex=x2-x1,ey=y2-y1;
    if(ex==0 && ey==0){
        cout<<0<<endl;
    }else if(ex==0 || ey==0){
        if((ex+ey)%2==0) cout<<ex+ey<<endl;
        else cout<<-1<<endl;
    }else{
        if(ex*ey>0){
            ex=abs(ex),ey=abs(ey);
            if(ex%2+ey%2==2) cout<<ex+ey-1<<endl;
            else if(ex%2+ey%2==0) cout<<ex+ey<<endl;
            else cout<<-1<<endl;
        }else{
            ex=abs(ex),ey=abs(ey);
            if(ex%2+ey%2==2) cout<<ex+ey+1<<endl;
            else if(ex%2+ey%2==0) cout<<ex+ey<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}