#include <iostream>
using namespace std;
const int maxx = 10000005;
int cnt=0;
int vis[maxx],step[maxx];
bool check(int n){
    while(n){
        if(n%10==7)return 0;
        n/=10;
    }
    return 1;
}
void plant(int n){
    for(int i=1;i*n<=maxx;i++){
        vis[i*n]=-1;
    }
    return;
}
void pre(){ 
    for(int i=1;i<=maxx;i++){
        if(vis[i]==0){
            if(!check(i)){
                plant(i);
            }else{
                vis[i]=++cnt;
                step[cnt]=i;
            }
        }
    }
    return;
}   
int main(){
    pre();
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(vis[n]==-1){
            cout<<"-1"<<endl;
        }else {
            cout<<step[vis[n]+1]<<endl;
        }
    }
}
