#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
map<string,int> mp;
int main(){
    mp["tourist"]=3858;
    mp["ksun48"]=3679;
    mp["Benq"]=3658;
    mp["Um_nik"]=3648;
    mp["apiad"]=3638;
    mp["Stonefeang"]=3630;
    mp["ecnerwala"]=3613;
    mp["mnbvmar"]=3555;
    mp["newbiedmy"]=3516;
    mp["semiexp"]=3481;
    string s;
    cin>>s;
    cout<<mp[s]<<endl;
    return 0;
}