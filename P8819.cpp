#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<random>
#include<ctime>
#define N (500005)
#define M (1005)
#define ll long long
#define INF (0x3f3f3f3f)
#define mod (998244353)
#define PII pair<int,int>
#define ls(xxx) (xxx)<<1
#define rs(xxx) (xxx)<<1|1
using namespace std;
int q,n,m,a[N];
ll to[N],sum[N],tot,ans;
mt19937 rnd(random_device{}());
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        a[i]=rnd(); ans+=a[i];
    }
    for(int i=1,u,v;i<=m;i++){
        scanf("%d %d",&u,&v);
        to[v]+=a[u],
        sum[v]=to[v],
        tot+=a[u];
    }
    scanf("%d",&q);
    while(q--){
        int opt,u,v;
        scanf("%d %d",&opt,&u);
        switch(opt){
            case 1:
                scanf("%d",&v);
                to[v]-=a[u],tot-=a[u];
                break;
            case 2:
                tot-=to[u],to[u]=0;
                break;
            case 3:
                scanf("%d",&v);
                to[v]+=a[u],tot+=a[u];
                break;
            case 4:
                tot+=sum[u]-to[u],to[u]=sum[u];
                break;
        }
        if(tot==ans) puts("YES");
        else puts("NO");
    }
    return 0;
}
/*
for(int i = 1,t,u,v;i <= q;++i){
		scanf("%d%d",&t,&u);
		if(t == 1) scanf("%d",&v),to[v] -= a[u],tot -= a[u];
		if(t == 2) tot -= to[u],to[u] = 0;
		if(t == 3) scanf("%d",&v),to[v] += a[u],tot += a[u];
		if(t == 4) tot += sum[u] - to[u],to[u] = sum[u];
		puts(tot == ans ? "YES" : "NO");
	}*/