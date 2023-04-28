#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f
#define ll long long
#define N 10005
#define M 10005
using namespace std;
char s[3];
int t[30];
int main(){
    cin>>s;
    for(int i=0;i<3;i++){
        t[s[i]-'a']++;
    }
    for(int i=0;i<30;i++){
        if(t[i]==1){
            cout<<(char)(i+'a')<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}