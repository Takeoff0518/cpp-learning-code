#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int posi[100005];

vector<int> maker(const string& a) {
    int m=a.length();
    vector<int> number(m, 0);
    int j=0;
    for(int i=1;i<m;i++) {
        while(j>0&&a[i]!=a[j])j=number[j-1];
        if(a[i]==a[j])j++;
        number[i]=j;
    }
    return number;
}
int kmp(const string& s,const string& a) {
    int n=s.length();
    int m=a.length();
    vector<int> seac =maker(a);
    int sum=0;
    int j=0;
    for(int i=0;i<n;i++) {
        while(j>0&&s[i]!=a[j])j=seac[j-1];
        if(s[i]==a[j])j++;
        if(j==m){
            sum++;
            j=seac[j-1];
        }
    }
    return sum;
}

int solve(int n,string s,string a,string b){
    int count=0;
    for(int i=0;i<n;i++)if(s[i]=='?')count++,posi[count]=i;
    return count;
}
int main(){
    int n,sum=0;
    string s,a1="hakuka",b1="moyoseiko";
    cin>>n>>s;
    if(kmp(s,a1)==kmp(s,b1)){
        sum++;
    }
    cout<<sum;
}
