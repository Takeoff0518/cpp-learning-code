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
const int ls[16]={1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256};
bool check(int x){
    for(int t:ls){
        if(t==x) return true;
    }
    return false;
}
int main(){
    int a;
    cin>>a;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=a-i;j++) cout<<' ';
        for(int j=1;j<=i*2-1;j++){
            if(check(j)) cout<<'!';
            else cout<<'#';
        }
        cout<<endl;
    }
    return 0;
}