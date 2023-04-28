#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,x,y,z;
int ans[1005],idx;
struct node{
    int english,math;
    int sum,num;
}s[1005];
inline bool cmpA(node x,node y){
    if(x.math==y.math){
        return x.num<y.num;
    }
    return x.math>y.math;
}
inline bool cmpB(node x,node y){
    if(x.english==y.english){
        return x.num<y.num;
    }
    return x.english>y.english;
}
inline bool cmpC(node x,node y){
    if(x.sum==y.sum){
        return x.num<y.num;
    }
    return x.sum>y.sum;
}
int main(){
    cin>>n>>x>>y>>z;
    for(int i=1;i<=n;i++){
        cin>>s[i].math;
    }
    for(int i=1;i<=n;i++){
        cin>>s[i].english;
        s[i].num=i,s[i].sum=s[i].english+s[i].math;
    }
    sort(s+1,s+n+1,cmpA);
    for(int i=1;i<=x;i++){
        ans[++idx]=s[i].num;
    }
    sort(s+x+1,s+n+1,cmpB);
    for(int i=x+1;i<=x+y;i++){
        ans[++idx]=s[i].num;
    }
    sort(s+x+y+1,s+n+1,cmpC);
    for(int i=x+y+1;i<=x+y+z;i++){
        ans[++idx]=s[i].num;
    }
    sort(ans+1,ans+idx+1);
    for(int i=1;i<=idx;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}