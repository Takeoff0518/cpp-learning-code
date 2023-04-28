#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,q,last;
set<int> st;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>q;
    while(q--){
        int opt; cin>>opt;
        if(opt==1) st.insert(++last);
        else if(opt==2){
            int t; cin>>t;
            st.erase(t);
        }else cout<<*(st.begin())<<endl;
    }

    return 0;
}