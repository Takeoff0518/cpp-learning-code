#include<iostream>
#include<cstdio>
#define N 100005
using namespace std;
int n;
int stk[N],top;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        while(top && stk[top]>=x)
            top--;
        if(top)
            cout<<stk[top]<<' ';
        else
            cout<<-1<<' ';
        stk[++top]=x;
    }
    return 0;
}