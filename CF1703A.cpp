#include<iostream>
#include<cstdio>
using namespace std;
int n;
string s[1005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        for(int j=0;j<s[i].size();j++){
            if(s[i][j]>='a' && s[i][j]<='z'){
                s[i][j]=s[i][j]-'a'+'A';
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i]=="YES"){
            puts("YES");
        }else{
            puts("NO");
        }
    }
    return 0;
}