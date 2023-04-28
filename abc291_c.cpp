#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#define N (200005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n;
char s[N];
map<PII,bool> mp;
int x,y;
int main(){
    cin>>n;
    cin>>s+1;
    mp[make_pair(0,0)]=1;
    for(int i=1;i<=n;i++){
        if(s[i]=='R') x++;
        else if(s[i]=='L') x--;
        else if(s[i]=='U') y++;
        else if(s[i]=='D') y--;
        PII loc=make_pair(x,y);
        // printf("(%d,%d)\n",x,y);
        if(mp[loc]){
            puts("Yes");
            return 0;
        }else mp[loc]=1;
    }
    puts("No");
    return 0;
}