#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f
#define ll long long
#define N 1005
using namespace std;
/*
状态表示：f[i]
    集合：所有以第i个数结尾的上升子序列
    属性：最大值
状态计算：f[i]=max(f[j]+1),j=0,1,2,...,i-1
*/
int n;
int a[N],c[N];
int ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        c[i]=1;
        for(int j=1;j<=i-1;j++){
            if(a[j]<a[i]){
                
                c[i]=max(c[i],c[j]+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,c[i]);
    }
    cout<<ans<<endl;
    return 0;
}