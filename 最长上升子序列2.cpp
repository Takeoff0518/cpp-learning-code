#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (100005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod ((ll)(998244353))
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N];
int q[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int len=0;//当前最大长度
    q[0]=-INF;
    for(int i=0;i<n;i++){
        int l=0,r=len;
        while(l<r){
            int mid=l+r+1>>1;//上取整，+1
            if(q[mid]<a[i]) l=mid;
            else r=mid-1;
        }
        len=max(len,r+1);
        q[r+1]=a[i];
    }
    cout<<len<<endl;
    return 0;
}