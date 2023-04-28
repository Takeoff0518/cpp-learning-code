#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 200
#define PII pair<int,int>
#define l first
#define r second
using namespace std;
int n;
PII a[N];
int vis[N];
int ans=-100;
bool check(int left,int right,int idx){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i] && i!=idx){
            //printf("%d:",i);
            if(a[i].l>left && a[i].r<right){
                //printf("1 ");
                cnt++;
            }else if(a[i].l<left && a[i].r>right){
                //printf("2 ");
                cnt++;
            }else if(a[i].l<left && a[i].r>left){
                //printf("3 ");
                cnt++;
            }else if(a[i].l<right && a[i].r>right){
                //printf("4 ");
                cnt++;
            }
            //puts("");
        }
    }
    if(cnt>=2){
        return false;
    }
    return true;
}
int main(){
    // freopen("record.in","r",stdin);
    // freopen("record.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].l,&a[i].r);
    }
    sort(a+1,a+n+1);
    // for(int i=1;i<=n;i++){
    //     printf("%d %d\n",a[i].l,a[i].r);
    // }
    for(int i=1;i<=n-1;i++){
        int sum=1;
        vis[i]=1;
        //puts("------------");
        //printf("add:%d~%d\n",a[i].l,a[i].r);
        for(int j=i+1;j<=n;j++){
            if(check(a[j].l,a[j].r,j)){
               // printf("add:%d~%d\n",a[j].l,a[j].r);
                sum++;
                vis[j]=1;
            }
        }
        ans=max(ans,sum);
        memset(vis,0,sizeof(vis));
    }
    printf("%d\n",ans);
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}