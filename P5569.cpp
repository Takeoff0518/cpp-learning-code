#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define N (40005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,j,k,sum,ans;
vector<int> v;
int main(){
    scanf("%d",&n);
    v.push_back(INF-1);
    for(int i=1,t;i<=n;i++){
        scanf("%d",&t);
        v.push_back(t);
    }
    v.push_back(INF);
    while(n-->1){
        for(int k=1;k<=n;k++)
            if(v[k-1]<v[k+1])
                break;
        sum=v[k]+v[k-1];
        for(int j=k-1;j>=0;j--)
            if(v[j]>v[k]+v[k-1])
                break;
        v.erase(v.begin()+k-1);
        v.erase(v.begin()+k-1);
        v.insert(v.begin()+j+1,sum);
        ans+=sum;
    }
    printf("%d\n",ans);
    return 0;
}