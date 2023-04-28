#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define next nxt;
#define re register
using namespace std;
const int MAXN=2010;
int read()
{
    int f=0,s=0;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) f |= (ch=='-');
    for(; isdigit(ch);ch=getchar()) s = (s<<1) + (s<<3) + (ch^48);
    return f ? -s : s;
}
int f[MAXN][MAXN];
int main()
{
    int n,m;
    string a,b;
    cin>>a>>b; 
    n=a.length();
    m=b.length();
    memset(f,0x3f,sizeof(f));
    f[0][0]=0;
    for(int i=1;i<=max(n,m);i++)
	{
    	f[i][0]=f[0][i]=i;
	}
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++) 
        {
            if(a[i-1]==b[j-1])
            {
                f[i][j]=min(f[i][j],f[i-1][j-1]);
            }
            f[i][j]=min(f[i][j],f[i-1][j]+1);
            f[i][j]=min(f[i][j],f[i][j-1]+1);
            f[i][j]=min(f[i][j],f[i-1][j-1]+1);
        }
    }
    cout<<f[n][m]<<endl;
}
