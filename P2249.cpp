#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 1000005
using namespace std;
int n,m;
int a[N];
void qsort(int l,int r){
    if(l>=r)
        return;
    int x=a[l+r>>1];
    int i=l-1,j=r+1;
    while(i<j){
        do{
            i++;
        }while(a[i]<x);
        do{
            j--;
        }while(a[j]>x);
        if(i<j)
            swap(a[i],a[j]);
    }
    qsort(l,j);
    qsort(j+1,r);
}
int search(int x){
    int l=1,r=n;
    while(l<r){
        int mid=l+r>>1;
        if(a[mid]>=x)
            r=mid;
        else
            l=mid+1;
    }
    if(x==a[l])
        return l;
    return -1;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    qsort(1,n);
    for(int i=1;i<=m;i++){
        int t;
        scanf("%d",&t);
        printf("%d ",search(t));
    }
    return 0;
}