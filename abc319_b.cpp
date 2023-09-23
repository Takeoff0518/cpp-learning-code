#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n;
/*
给你一个正整数 N，打印一个长度为 (N+1) 的字符串 s 0 s 1 ...sN，定义如下。
对于每个 i=0,1,2,...,N，如果 N 的除数 j 介于 1 和 9 之间（包括 1 和 9），且 i 是 N/j 的倍数，则 s i 是对应于最小除数 j 的数字（因此，s i 将是 1、2、...、9 中的一个）；
如果不存在这样的 j，则 s i 为-。
*/
int ans[N];
int main(){
    cin>>n;
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<=n;i++){
        for(int j=1;j<=9;j++){
            if(n%j==0){
                if(i%(n/j)==0){
                    ans[i]=j;
                    break;
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        if(ans[i]==-1) cout<<'-';
        else cout<<ans[i];
    }
    return 0;
}