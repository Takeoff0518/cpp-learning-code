#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#define N 100005
#define l first
#define r second
using namespace std;
typedef pair<int,int> PII;
int n;
int ans=0;
vector<PII> b;
PII a[N];
int main(){
    scanf("%d %d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",a[i].left,a[i].r);
    }
    sort(a+1,a+n+1);
    b.push_back(a[1]);
    for(int i=2;i<=n;i++){
        PII t1=b.back(),t2=a[i];
        if(t2.x>t1.y){

        }
    }
    return 0;
}