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
int co,th,p,e;
int main(){
    cin>>co>>th;
    for(int i=1;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(i+j==co && i*2+j==th){
                cout<<i<<' '<<j<<endl;
                return 0;
            }
        }
    }
    cout<<"Error"<<endl;
    return 0;
}