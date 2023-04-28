#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int t,id,c,f,n,m;
bool g[N][N];
int pre_sum[N][N];
int cnt_col[N],cnt_sum[N],cnt_id,last;
int ans_c,ans_f;

inline void solve(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=m;j++){
            if(cnt_col[i]-cnt_col[j]>1){
                ans_c+=(cnt_col[i]-1)*(cnt_col[j]-1);
            }
        }
    }
}
int main(){
    scanf("%d %d",&t,&id);
    while(t--){
        scanf("%d %d %d %d",&n,&m,&c,&f);
        ans_c=ans_f=0;
        for(int i=1;i<=n;i++){
            char tmp[N];
            scanf("%s",tmp+1);
            for(int j=1;j<=m;j++){
                if(tmp[j]=='1') g[i][j]=1;
                else g[i][j]=0;
                pre_sum[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(g[i][j]==1){
                    pre_sum[i][j]=0;
                }else pre_sum[i][j]=pre_sum[i][j+1]+1;   
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //        
        // cout<<pre_sum[i][j];
        //     }
        //     cout<<endl;
        // }
        for(int j=1;j<=m;j++){
            cnt_id=0,last=-1;
            //预处理
            for(int i=n;i>=1;i--){
                if(pre_sum[i][j]>1){
                    if(last!=-1) last=j;
                    ++cnt_id;
                    cnt_col[cnt_id]=j;
                    cnt_sum[cnt_id]=pre_sum[i][j];
                    cout<<last<<endl;
                }else if(pre_sum[i][j]==0){
                    if(last!=-1){ //判断到一块的结尾，开搞！
                        solve();
                        cout<<"oops!"<<endl;
                    }
                    cnt_id=0,last=-1;
                }
            }
        }
        cout<<ans_c<<endl;
    }
    return 0;
}