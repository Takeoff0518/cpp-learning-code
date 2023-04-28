#include<iostream>
#include<cstdio>
#define N 25000
#define M 2005
using namespace std;
int v[N],w[N],s[N],f[N];
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    int cnt=0;
    for(int i=1;i<=n;i++){
        int a,b,s;
        scanf("%d %d %d",&a,&b,&s);
        int k=1;
        while(k<=s){
            cnt++;
            v[cnt]=a*k;
            w[cnt]=b*k;
            s-=k;
            k<<=1;//k*=2;
        }
        if(s){//如果还有剩余
            cnt++;
            v[cnt]=a*s;
            w[cnt]=b*s;

        }
    }
    n=cnt;
    /*
    f[i,j]=max(f[i-1,j],f[i-1,j-v]+w,f[i-1,j-2v]+2w,....,f[i-1,j-sv]+sw);
    f[i,j]=max(        ,f[i-1,j-v],  f[i-1,j-2v]+w,.....,f[i-1,j-sv]+(s-1)w,f[i-1,j-(s+1)v]+sw)
    优化：二进制枚举
    s=200
    1,2,4,8,16,32,64,73...
    可以用2^k拼凑出0~2^(k+1)-1中任意的数
    将其中的一维优化成log
    */
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    printf("%d\n",f[m]);
    return 0;
}