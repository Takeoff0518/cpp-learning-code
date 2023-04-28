#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#define N (1005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int n,m;
int a[N][N];
ll ans=0;
int dx[2]={0,1};
int dy[2]={1,0};
map<int,bool> num;
bool vis[N][N];
void dfs(int x,int y){
    if(num[a[x][y]]) return;
    if(x==n && y==m){
        if(!num[a[x][y]]){
            ans++;
        }return;
    }
    if(x<1 || x>n || y<1 || y>m) return;
    num[a[x][y]]=1;
    dfs(x+1,y); dfs(x,y+1);
    num[a[x][y]]=0;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    dfs(1,1);
    cout<<ans<<endl;
    return 0;
}