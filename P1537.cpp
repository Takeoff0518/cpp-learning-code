#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (15)
#define M (20005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int a[N],t,sum,cnt,st[M];
bool f[M*10];
int main(){
    while(1){
        cnt=sum=0;
        for(int i=1;i<=6;i++){
            scanf("%d",&a[i]);
            sum+=a[i]*i;
            int loc=1;
            while(a[i]>=loc){
                st[++cnt]=loc*i;
                a[i]-=loc;
                loc<<=1;
            }
            if(a[i]) st[++cnt]=a[i]*i;
        }
        if(sum%2){
            printf("Collection #%d:\nCan't be divided.\n\n",++t);
            continue;
        }
        if(cnt==0) break;
        sum>>=1;
        memset(f,0,sizeof(f)); f[0]=1;
        for(int i=1;i<=cnt;i++){
            for(int j=sum;j>=st[i];j--){
                f[j]=f[j] || f[j-st[i]];
            }
        }
        if(f[sum]) printf("Collection #%d:\nCan be divided.\n\n",++t);
        else printf("Collection #%d:\nCan't be divided.\n\n",++t);
    }
    return 0;
}