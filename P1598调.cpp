#include<iostream>
#include<string>
#include<cstring>
int d[26];
int b=27;
int max(int *A,int s){
    int maxn=0;
    for(int i=0;i<s;i++)
    if(A[i]>maxn){
        maxn=A[i];
        b=i;
    }
    return maxn;
}
using namespace std;
int main(){
    string a[4];
    int ans;
    char er;
    getline(cin,a[0]);
    getline(cin,a[1]);
    getline(cin,a[1]);
    getline(cin,a[2]);
    getline(cin,a[2]);
    getline(cin,a[3]);
    getline(cin,a[3]);
    for(int i=0;i<4;i++){
        for(int j=0;j<a[i].length();j++)
        d[a[i][j]-'A']++;
    }
    ans=max(b,26);
    for(int i=ans;i>=1;i--){
        for(int j=0;j<26;j++)
        if(d[j]>=i)
        cout<<"*";
        else
        cout<<" ";
        cout<<endl;
    }
    for(int i=0;i<26;i++){
        er=i+'A';
        cout<<er<<' ';
    }
}