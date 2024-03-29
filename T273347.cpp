#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1e5,M=1e4;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,q,cnt=1;
string s[2*N];
bool caps[N];//capslock before i
string fun(string str){
    for(int i=0;i<str.size();i++){
        if('A'<=str[i] && str[i]<='Z'){
            str[i]=str[i]-'A'+'a';
        }else if('a'<=str[i] && str[i]<='z'){
            str[i]=str[i]-'a'+'A';
        }
    }
    return str;
}
int caps_cnt=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        string tmp;
        cin>>tmp;
        if(tmp=="CapsLock"){
            caps[cnt]^=1;
        }else{
            s[cnt++]=tmp;
        }
    }
    cnt--;
    for(int i=1;i<=cnt;i++){
        caps_cnt+=caps[i];
    }

    if(caps_cnt&1){
        for(int i=1;i<=cnt;i++){
            caps[i+cnt]=caps[i];
            s[i+cnt]=s[i];
        }
        cnt<<=1;
    }
    bool mode=0;
    for(int i=1;i<=cnt;i++){
        mode^=caps[i];
        if(mode){
            s[i]=fun(s[i]);
        }
        //cout<<s[i]<<' ';
    }
    // cout<<endl;
    // for(int i=1;i<=cnt;i++){
    //     cout<<s[i]<<' ';
    // }
    // cout<<endl;
    // for(int i=1;i<=cnt;i++){
    //     cout<<caps[i]<<' ';
    // }
    // cout<<endl<<caps_cnt<<' '<<cnt<<endl;
    scanf("%d",&q);
    s[0]=s[cnt];
    while(q--){
        ll x;
        scanf("%lld",&x);
        //cout<<x%cnt<<' ';
        cout<<s[x%cnt]<<endl;
    }
    return 0;
}