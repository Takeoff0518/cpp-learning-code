#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 10005
#define M 10005
using namespace std;
int main(){
    unsigned short x,y;
    cin>>x>>y;
    x=(x|x<<2)&0x33;
    x=(x|x<<1)&0x55;
    y=(y|y<<2)&0x33;
    y=(y|y<<1)&0x55;
    unsigned short z=x|y<<1;
    cout<<z<<endl;
    return 0;
}