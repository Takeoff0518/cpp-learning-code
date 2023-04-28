#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=5e6+5,M=1005;
const int p=233317;
const int INF=0x3f3f3f3f;
using namespace std;
char s[N];
int n,len,base=131;
int mp[300000];
unsigned ll hashs(char ss[]){
    int len=strlen(ss);
    unsigned ll ans=0;
    for (int i=0;i<len;i++){
        ans=(ans*base+(unsigned ll)(ss[i]-'A'+1))%p;
    }
    return ans;
}
int main(){
    cin>>s;
    cin>>n;
    len=strlen(s);
    for(int i=0;i<len-n+1;i++){
        char tmp[50];
        for(int j=0;j<n;j++){
            tmp[j]=s[i+j];
        }
        // cout<<tmp<<' ';
        tmp[n]='\0';
        mp[hashs(tmp)]++;
    }
    int ans=-INF;
    for(int i=0;i<300000;i++){
        // cout<<mp[i];
        ans=max(ans,mp[i]);
    } 
    printf("%d\n",ans);
    return 0;
}