#include<iostream>
#include<cstdio>
#include<cstring>
#define N 50005
#define logN 18
using namespace std;
int n,q;
int f_max[N][logN],f_min[N][logN];
int Log[N],a[N];
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
       scanf("%d",&a[i]); 
    }
    Log[0]=-1;
    for(int i=1;i<=n;i++){
        Log[i]=Log[i>>1]+1;
        f_max[i][0]=f_min[i][0]=a[i];
    }
    for(int j=1;j<=logN;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f_max[i][j]=max(f_max[i][j-1],f_max[i+(1<<j-1)][j-1]);
            f_min[i][j]=min(f_min[i][j-1],f_min[i+(1<<j-1)][j-1]);
        }
    }
    for(int i=1;i<=q;i++){
        int x,y,s;
        scanf("%d %d",&x,&y);
        s=Log[y-x+1];
        printf("%d\n",max(f_max[x][s],f_max[y-(1<<s)+1][s])-min(f_min[x][s],f_min[y-(1<<s)+1][s]));
    }
    return 0;
}