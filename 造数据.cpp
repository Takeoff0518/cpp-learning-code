#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<random>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
mt19937 rnd(random_device{}());
int main(){
    freopen("ex_a5.in","w",stdout);
    for(int i=1;i<=200000;i++){
        int tmp=rnd()%2+1;
        if(tmp==1){
            putchar('L');
        }else if(tmp==2){
            putchar('R');
        }else if(tmp==3){
            putchar('L');
        }else{
            putchar('R');
        }
    }
    printf("\n998244353\n");
    return 0;
}