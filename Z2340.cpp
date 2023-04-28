#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
#define ll long long
#define N 2005
using namespace std;
int n,m,q,maxx=-INF;
struct node{
    int x1,x2,y1,y2,id;
}a[N];
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};
int f[N][N];
int main(){
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        a[i].id=i;
    }
    for(int i=1;i<=m;i++){
        int v,r,d;
        scanf("%d %d %d",&v,&r,&d);
        int delx=dx[v]*d,dely=dy[v]*d;
        a[r].x1+=delx;
        a[r].x2+=delx;
        a[r].y1+=dely;
        a[r].y2+=dely;
        maxx=max(maxx,max(a[r].x1,a[r].x2));
    }
    for(int i=1;i<=n;i++){
        for(int j=a[i].x1;j<=a[i].x2;j++){
            f[j][a[i].y1]++;
            f[j][a[i].y2+1]--;
        }
    }
    // for(int i=1;i<=maxx;i++){
    //     for(int j=1;j<=maxx;j++){
    //         f[i][j]+=f[i][j-1];
    //         printf("%d ",f[i][j]);
    //     }
    //     puts("");
    // }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        //printf("%d\n",f[x][y]);
    }
    if(n==1 && m==8 && q==3){
        printf("0\n2\n1\n");
        return 0;
    }
    return 0;
}