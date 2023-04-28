#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
char q[505][505];
int nx[4]={0,0,1,-1};
int ny[4]={1,-1,0,0};
void dfs1(int x,int y)
{
    if(x<1||y<1||x>n||y>m||q[x][y]!='0'){
        //cout<<"lxl"<<endl;
        return;
    }
    q[x][y]='*';
    ans++;
    int dx,dy;
    for(int i=0;i<4;i++)
    {
        dx=x+nx[i],dy=y+ny[i];
        dfs1(dx,dy);
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(q,'0',sizeof(q));
    for(int i=1;i<=n;i++)
    {
        getchar();
        for(int o=1;o<=m;o++)
        {
            scanf("%c",&q[i][o]);
            //cin>>q[i][o];
        }
    }
    for(int i=1;i<=n;i++)
        if(q[i][1]=='0')dfs1(i,1);
    for(int i=1;i<=m;i++)
        if(q[1][i]=='0')dfs1(1,i);
    for(int i=1;i<=n;i++)
        if(q[i][m]=='0')dfs1(i,m);
    for(int i=1;i<=m;i++)
        if(q[n][i]=='0')dfs1(n,i);
    ans=0;
    for(int i=2;i<=n;i++)
    {
        for(int o=2;o<=m;o++)
        {
            if(q[i][o]=='0')
            {
                dfs1(i,o);
            }
        }
    }
    cout<<ans;
    return 0;
}