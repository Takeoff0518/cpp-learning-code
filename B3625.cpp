#include<bits/stdc++.h>
using namespace std;
int n,m;
bool b[110][110];char a[110][110];
int xx[5]={0,0,-1,0,1};
int yy[5]={0,-1,0,1,0};
void dfs(int x,int y){
    for(int i=1;i<=4;i++){
        if(x+xx[i]<=n&&x+xx[i]>=1){
            if(y+yy[i]<=m&&y+yy[i]>=1){
                if(a[x+xx[i]][y+yy[i]]=='.'&& b[x+xx[i]][y+yy[i]]==0){
                    b[x+xx[i]][y+yy[i]]=1;
                    dfs(x+xx[i],y+yy[i]);
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    dfs(1,1);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<b[i][j];
    //     }
    //     cout<<endl;
    // }
    if(b[n][m]==1){
        cout<<"Yes";
    } else cout<<"No";

    return 0;
} 