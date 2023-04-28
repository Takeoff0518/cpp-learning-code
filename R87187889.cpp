#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<map>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
int max(int x,int y){return x<y?y:x;}
int min(int x,int y){return x<y?x:y;}
const int MAXN = 1000060;
const int INF = 0x3f3f3f3f;
inline ll read(){
   ll s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline void out(ll a){
	if(a<0) putchar('-'),a=-a;
    if(a>=10)out(a/10);putchar(a%10+'0');
}
int d[MAXN],num_edge,n,m,n,s,t;
bool vis[MAXN];
struct edeg{
	int to,next,cost;
	#define at(x) a[x].to
	#define an(x) a[x].next
	#define ac(x) a[x].cost
}a[MAXN*6];
int head[MAXN];
void add(int x,int y,int z){
	at(num_edge)=y;
	an(num_edge)=head[x];
	ac(num_edge)=z;
	head[x]=num_edge++;
}
void Dijkstra(int s)
{
    memset(d,0x3f,sizeof(d));
    d[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(!vis[u])
        {
            vis[u]=1;
            for(int i=head[u];i;i=an(i))
            {
                int to=a[i].to;
                if(d[to]>d[u]+a[i].cost) 
                {
                    d[to]=d[u]+a[i].cost;
                    q.push(make_pair(d[to],to));
                }
            }
        }
    }
}

int main()
{
    n=read(),m=read(),n=read();
	s=read(),t=read();
    for(int i=0,u,v,c;i<m;++i)
    {
        u=read(),v=read(),c=read();
        add(u,v,c);
        add(v,u,c);
        for(int j=1;j<=n;++j)
        {
            add(u+(j-1)*n,v+j*n,0);
            add(v+(j-1)*n,u+j*n,0);
            add(u+j*n,v+j*n,c);
            add(v+j*n,u+j*n,c);
        }
    }
    for(int i=1;i<=n;++i){
		add(t+(i-1)*n,t+i*n,0);
	}
    Dijkstra(s);
    out(d[t+n*n]);
    return 0;
}