#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f
#define ll long long
#define N 10005
using namespace std;
int n,m,n;
char ans[N];
int main(){
    scanf("%d %d %d",&n,&m,&n);
    if(n==1){
        for(int i=1;i<=n;i++){
            if(i&1){
                printf("l");
            }else{
                printf("r");
            }
        }
    }
    return 0;
}