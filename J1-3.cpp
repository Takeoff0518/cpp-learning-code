#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 10005
#define M 10005
using namespace std;
int main(){
    int x=101;
    int y=201;
    int *p=&x;
    int *q=&y;
    p=q;
    cout<<x<<' '<<y;
    return 0;
}