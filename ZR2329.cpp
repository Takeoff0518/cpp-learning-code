#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#define INF 0x3f3f3f3f
#define ll long long
#define N 10005
#define M 10005
using namespace std;
string a,b;
string reverse(string s){
    int tmp=s.size();
    for(int i=0;i<(tmp>>1);i++){
        swap(s[i],s[tmp-i-1]);
    }
    return s;
}
string substr(string s,int st,int ed){
    string tmp="";
    for(int i=st;i<=ed;i++){
        tmp+=s[i];
    }
    return tmp;
}
map<string,bool>vis;
int ans=1;
int main(){
    cin>>a>>b;
    int len_a=a.size(),len_b=b.size();
    string c;
    //cout<<a<<' '<<b<<endl;
    for(int i=0;i<len_a;i++){
        c=substr(a,0,i);
        if(vis[c]==false){
            vis[c]=true;
            ans++;
        }
    }
    for(int i=len_b-1;i>=0;i--){

    }
    for(int i=0;i<len_a;i++){
        ans++;
        for(int j=len_b-1;j>=0;j--){
            c=substr(a,0,i)+substr(b,j,len_b-1);
            if(vis[c]==false){
                vis[c]=true;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}