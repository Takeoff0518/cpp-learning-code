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
void stringToChar(string &source, char &target[]){
    for(auto i:source){
        target[i]=source[i];
    }
}
char a[100];
int main(){
    stringToChar("abc",a);
    return 0;
}