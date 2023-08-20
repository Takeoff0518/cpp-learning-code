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
int n,q;
char s[N],s2[N<<1],len_p;
int p[N<<1];
void manacher(){
    len_p=0;
    s2[len_p++]='^';
    for(int i=0;i<n;i++){
        s2[len_p++]='#';
        s2[len_p++]=s[i];
    }
    s2[len_p++]='#';
    s2[len_p++]='@';
    int r=0,mid=0;
    for(int i=1;i<len_p-1;i++){
        p[i]=r>i ? min(p[mid*2-i],r-i) : 1;
        while(s2[i+p[i]]==s2[i-p[i]]) p[i]++;
        if(i+p[i]>r){
            r=i+p[i];
            mid=i;
        }
    }
    // s[i]->p[j]: j=2+i*2
    for(int i=1;i<=n;i++) printf("%d ",p[i]);
}
int main(){
    scanf("%d %d",&n,&q);
    cin>>s;
    manacher();
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        
    }
    return 0;
}