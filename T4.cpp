#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1005,M=1005;
const int INF=0x3f3f3f3f;
const int p=998244353;
using namespace std;
int ans,n,m;
int a[N],b[N],c[N];
bool sp1=1,sp2=1,sp3=1;
bool type[N];

int solve(int v,int w){
    int f[20][20][20];
    memset(f,0,sizeof(f));
    for(int i=1;i<=m;i++){
        for(int j=v;j>=0;j--){
            for(int k=w;k>=0;k--){
                if(j>=b[i] && k>=c[i]){
                    f[i][j][k]=max(f[i-1][j][k],f[i-1][j-b[i]][k-c[i]]+1);
                }else{
                    f[i][j][k]=f[i-1][j][k];
                }
            }
        } 
    }
    return f[m][v][w];
}
int dian,zige;
void dfs(int x){
    if(x==n+1){
        // for(int i=1;i<=n;i++){
        //     cout<<type[i]<<' ';
        // }
        // cout<<endl;
        for(int i=1;i<=n;i++){
            dian+=a[i]*type[i];
            zige+=!type[i];
        }
        // cout<<zige<<' '<<dian<<endl;
        ans+=solve(dian,zige);
        dian=zige=0;
        return;
    }
    type[x]=1;
    dfs(x+1);
    type[x]=0;
    dfs(x+1);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d",&b[i],&c[i]);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}