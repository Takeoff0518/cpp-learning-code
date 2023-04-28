#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=100005,M=40;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int n,m,a[N];
int c[M],c2[N][M];
void init(int *t,int l,int r){
    for(int i=l;i<=r;i++){
        for(int j=0;j<32;j++){
            if(a[i]&(i<<j)){
                t[j]++;
            }
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for(int j=0;j<32;j++){//记录每一位 1 的个数
            if(a[i]&(1<<j)){
                c[j]++;
            }
            c2[i][j]=c2[i-1][j]+c[j];
        }
    }
    if(n<=110 && m<=110){
        while(m--){
            int opt,l,r,v;
            scanf("%d",&opt);
            if(opt==1){
                scanf("%d %d %d",&l,&r,&v);
                for(int i=l;i<=r;i++){
                    a[i]^=v;
                }
            }else{
                scanf("%d %d",&l,&r);
                ll ans=0;
                for(int i=1;i<=n;i++){
                    for(int j=i+1;j<=n;j++){
                        ans+=a[i]^a[j];
                    }
                }
                printf("%d\n",ans);
            }
        }
        return 0;
    }else{
        while(m--){
            int opt,l,r,v;
            scanf("%d",&opt);
            //c2[i][j] 1~i 在j位上1的个数
            if(opt==1){
                scanf("%d %d %d",&l,&r,&v);
                if(l==r){
                    int bef[M]={0},now[M]={0};
                    init(bef,l,r);
                    a[l]^=v;
                    init(now,l,r);
                    for(int i=0;i<32;i++){
                        c[i]=c[i]-bef[i]+now[i];
                    }
                }
            }else{
                scanf("%d %d",&l,&r);
                if(l==1 && r==n){
                    ll ans=0;
                    for(int i=0;i<32;i++){
                        ans+=(ll)(n-c[i])*c[i]*(1<<i);
                    }
                    printf("%lld\n",ans);
                }
            }
            // for(int i=0;i<=8;i++){
            //     printf("%d ",c[i]);
            // }
            //puts("\n---");
        }
        return 0;
    }
    puts("qaq");
    return 0;
}