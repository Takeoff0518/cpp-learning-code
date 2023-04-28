#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int solved[30];
int t,n,ans;
string s;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        ans=0;
        memset(solved,0,sizeof(solved));
        for(int i=0;i<n;i++){
            if(solved[s[i]-'A']==0){
                ans++;
            }
            ans++;
            solved[s[i]-'A']++;
        }
        cout<<ans<<endl;
    }
    return 0;
}