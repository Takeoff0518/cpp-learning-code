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
int a[N],b[N],c[N];
int groups[N];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(int j=0;j<n;j++){
        int group=(j-b[j]+n)%n;
        groups[group]=max(groups[group],b[j]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if((i+j)%n==k){
                    c[k]=max(c[k],a[i]+b[j]);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",c[i]);
    }
    printf("\n");
    return 0;
}