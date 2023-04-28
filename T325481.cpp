#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define N (105)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
char a[N],b[N];
int lena,lenb;
int cnta,cntb;
int main(){
    cin>>a+1>>b+1;
    lena=strlen(a+1),lenb=strlen(b+1);
    for(int i=1;i<=lena;i++)
        if(a[i]=='.'){
            cnta=i+1;
            break;
        }
    for(int i=1;i<=lenb;i++)
        if(b[i]=='.'){
            cntb=i+1;
            break;
        }
    for(int i=0;i<12;i++){
        if(a[cnta+i]!=b[cntb+i]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}