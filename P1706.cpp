#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 10005
#define M 10005
using namespace std;
int n,num[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        num[i]=i;
    }
    do{
        for(int i=1;i<=n;i++){
            printf("%5d",num[i]);
        }
        puts("");
    }while(next_permutation(num+1,num+n+1));
    return 0;
}