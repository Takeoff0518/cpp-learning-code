#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=1005,M=1002;
const int INF=0x3f3f3f3f;
const int p=1e9+7;
using namespace std;
struct matrix{
    int n,m;
    ll z[N][N];
    matrix(){
        n=m=0;
        memset(z,0,sizeof(z));
    }
};
matrix t;
matrix operator * (const matrix &m1,const matrix &m2){
    memset(t.z,0,sizeof(t.z));
    t.n=m1.n;
    t.m=m2.m;
    for(int i=1;i<=t.n;i++){
        for(int k=1;k<=m1.m;k++){
            for(int j=1;j<=t.m;j++){
                t.z[i][j]+=m1.z[i][k]*m2.z[k][j];
            }
        }
    }
    return t;
}
matrix m[3],ans;
ll sum=0;
int main(){
    for(int k=0;k<3;k++){
        scanf("%d %d",&m[k].n,&m[k].m);
        for(int i=1;i<=m[k].n;i++){
            for(int j=1;j<=m[k].m;j++){
                scanf("%d",&m[k].z[i][j]);
            }
        }
        if(k==0){
            ans=m[0];
        }else{
            ans=ans*m[k];
        }
    }
    for(int i=1;i<=ans.n;i++){
        for(int j=1;j<=ans.m;j++){
            sum+=ans.z[i][j];
            sum%=p;
        }
    }
    printf("%lld\n",sum);

    return 0;
}