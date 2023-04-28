#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define INF 2e9
#define ll long long
#define N 100005
using namespace std;
/*
状态表示：f[i]
    集合：所有以第i个数结尾的上升子序列
    属性：最大值
状态计算：f[i]=max(f[j]+1),j=0,1,2,...,i-1
*/
int n;
int a[N],f[N],q[N];
int ans=0,len=0;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    q[0]=-INF;
    for(int i=0;i<n;i++){
        int l=0,r=len;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(q[mid]<a[i]){
                l=mid;
            }else{
                r=mid-1;
            }
        }
        len=max(len,r+1);
        q[r+1]=a[i];
    }
    cout<<len<<endl;
    return 0;
}