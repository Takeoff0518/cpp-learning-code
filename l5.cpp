#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N (1000005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,a[N],s[N],s2[N],idx,cnt;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1]) s[idx]++;
        else{
            s[++idx]=1;
            s2[idx]=a[i];
        }
    }
    // for(int i=1;i<=idx;i++) printf("%d ",s[i]);
    int rest=idx;
    int l=1,r=n;
    while(rest>2){
        if(r-l>2){
            int minn=min(s[l],s[r]);
            s[l]-=minn,s[l+1]+=minn;
            s[r]-=minn,s[r-1]+=minn;
            cnt+=2*minn;
            if(!s[l]) l++,rest--;
            if(!s[r]) r--,rest--;
        }else{
            while(s[l] && s[r]){
                s[l]--,s[l+1]++;
                cnt++;
                if(!s[l]){
                    l++;
                    rest--;
                    break;
                }
                s[r]--,s[r-1]++;
                cnt++;
                if(!s[r]){
                    r--;
                    rest--;
                    break;
                }
            }
        }
    }
    // for(int i=1;i<=idx;i++) printf("%d ",s[i]);
    // puts("");

    printf("%d %d %d",cnt,s2[l],s2[r]);
    return 0;
}