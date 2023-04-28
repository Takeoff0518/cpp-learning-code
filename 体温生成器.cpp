#include<iostream>
#include<cstring>
#include<cstdio>
#include<random>
#define INF 0x3f3f3f3f
#define ll long long
#define N 10005
#define M 10005
using namespace std;
mt19937 rnd(random_device{}());
int fun(int l,int r){
    int tmp=rnd()>>1;
    if(l>r)
        swap(l,r);
    return l+tmp%(r-l);
}
int main(){
    for(int i=1;i<=14;i++){
        cout<<fun(362,371)<<' '<<fun(362,371)<<endl;
    }
    return 0;
}