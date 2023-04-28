#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
const int N=105,M=1e4;
const int INF=0x3f3f3f3f;
const int p=1e9;
using namespace std;
int n,m,a[N],f[2][32768+5];
//设f[i][st]表示确定前i位
//且末M位是st的满足题意的二进制序列个数，
//初始时f[0][0]=1。
//转移时，若i≠0 (mod M)，则只需取当前位curbit令其与倒数第M位不同时为1即可;若i=0 (mod M)，那么当前位在满足以上的条件下还需要使新得到的末M位不能被ci整除。以此即可求出所有状态。
//最后，统计Ans=sum f[N*M][st]的值即可。
//该算法的时间复杂度是O(N*M*2M )，加之对取模和判断运算的优化，可以通过本题的全部测试数据。
void work(){
    int mv=(1<<m)-1,
        v2=1<<(m-1),
        opt1=0,opt2=1;
    memset(f,0,sizeof(f));
    f[0][0]=1;
    for(int t=1;t<=n;t++){
        for(int i=1;i<=m;i++,\
            swap(opt1,opt2),\
            memset(f[opt2],0,sizeof(f[opt2]))){
            for(int j=0,j2=0;j<=mv;j+=2,j2++){
                f[opt2][j|1]=f[opt1][j2];
                f[opt2][j]=(f[opt1][j2]+\
                            f[opt1][j2|v2])%p;
            }
        }
        for(int j=0;j<=mv;j++){
            if(j%a[t]==0){
                f[opt1][j]=0;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=mv;i++){
        if(i%a[n]){
            ans=(ans+f[opt1][i])%p;
        }
    }
    printf("%d\n",ans);
}
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        work(); 
    }
    
    return 0;
}