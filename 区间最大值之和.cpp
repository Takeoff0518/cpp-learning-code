#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#define INF 0x3f3f3f3f
#define ll long long
#define N 1000005
using namespace std;
int l[N],r[N],n,a[N];
stack<int> st;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    //r
    for(int i=1;i<=n;i++){
        while(!st.empty() && a[i]>=a[st.top()]){
            r[st.top()]=i-1;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        r[st.top()]=n;
        st.pop();
    }
    //l
    for(int i=n;i>=1;i--){
        while(!st.empty() && a[i]>=a[st.top()]){
            l[st.top()]=i+1;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        l[st.top()]=1;
        st.pop();
    }
    // printf("l:");
    // for(int i=1;i<=n;i++){
    //     printf("%d ",l[i]);
    // }
    // printf("\nr:");
    // for(int i=1;i<=n;i++){
    //     printf("%d ",r[i]);
    // }
    // puts("");
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=a[i]*(i-l[i]+1)*(r[i]-i+1);
    }
    printf("%lld",ans);
    return 0;
}
/*
解法二:
对于每个数a[i],问有多少个区间最大值是a[i] 
设有b[i]个区间的最大值是a[i]
a[i]*b[i]，求b[i]
for(int i=1;i<=n;i++){
    从 i 往前走走到区间左侧，位置记为 l
    从 i 往后走走到区间右侧，位置记为 r
    int l=i;
    while(l>=1 && a[l]<=a[i])
    while(r<=....)
    b[i]=(i-l+1);
    sum+=a[i]*b[i];
}
解法三：
维护一个单调栈，
将所有数字依次入栈
如果一个在栈中的数a[i]
被要入栈的a[j]弹栈了(a[j]>a[i])
那么r[i]=j-1;
再维护一个单调栈
反向（从右往左放数）求出l[i]
ans+=a[i]*(i-l[i]+1)*(r[i]-i+1)
*/