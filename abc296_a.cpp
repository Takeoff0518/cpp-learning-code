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
int n;
char s[N];
int main(){
    cin>>n;
    cin>>s+1;
    if(n==1){
        puts("Yes");
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            if(s[i]!=s[(i-1)%2+1]){
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}