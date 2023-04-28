#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100005
#define logN 18
using namespace std;
int n,m,x,y,a[N],f[N][logN],Log[N];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    Log[0]=-1;
    for(int i=1;i<=n;i++){
        f[i][0]=a[i];
        Log[i]=Log[i>>1]+1;//log[i]=log[i/2]+1;
    }
    for(int j=1;j<=logN;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){//i+2^j--1<=n
            f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
            //f[i][j]=max(f[i][j-1],j[i+2^j-1][j-1])
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        int s=Log[y-x+1];
        printf("%d\n",max(f[x][s],f[y-(1<<s)+1][s]));
    }
    return 0;
}
