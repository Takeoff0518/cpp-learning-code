#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 10005
#define M 10005
using namespace std;
int t;
int tong[256];
bool f=0;
int main(){
    cin>>t;
    for(int i=1;i<=t;i++){
        string s;
        cin>>s;
        f=0;
        memset(tong,0,sizeof(tong));
        for(int j=0;j<s.size();j++){
            tong[s[j]]++;
        }
        if(tong['X'] && tong['D']){
            f=1;
        }
        for(int j=0;j<130;j++){
            if(tong[j]>=4){
                f=1;
            }
        }
        if(f){
            puts("Yes");
        }else{
            puts("No");
        }
    }
    return 0;
}