#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 0x0f0f0f0f0f0f0f0f;
int n, m, g[210][210], h[210][210], f[210][210];
bool vis[210];
void Dijkstra(int S, int *dis, int *fa)
{
    for (int i = 0; i <= n; i++)
        dis[i] = inf, vis[i] = false;
    dis[S] = 0;
    while (true)
    {
        int x = 0;
        for (int i = 1; i <= n; i++)
            if (!vis[i] && dis[i] < dis[x])
                x = i;
        if (!x)
            break;
        vis[x] = true;
        for (int y = 1; y <= n; y++)
            if (dis[y] > dis[x] + g[x][y])
                dis[y] = dis[x] + g[x][y], fa[y] = x;
    }
    //	for(int i=1;i<=n;i++)printf("%d ",dis[i]);puts("");
}
int dis1[210], fa1[210], sid1[210], af1[210], disn[210], fan[210], sidn[210], afn[210], dist[210], fat[210];
int u[51000], v[51000], c[51000], d[51000];
int res = inf;
signed main()
{
    scanf("%lld%lld", &n, &m), memset(g, inf, sizeof(g)), memset(f, inf, sizeof(f));
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld%lld", &u[i], &v[i], &c[i], &d[i]);
        if (g[u[i]][v[i]] >= c[i])
            f[u[i]][v[i]] = g[u[i]][v[i]], g[u[i]][v[i]] = c[i];
        else
            f[u[i]][v[i]] = min(f[u[i]][v[i]], c[i]);
    }
    //	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)printf("%d ",g[i][j]);puts("");}
    //	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)printf("%d ",f[i][j]);puts("");}
    Dijkstra(1, dis1, fa1), Dijkstra(n, disn, fan);
    res = min(res, dis1[n] + disn[1]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            h[i][j] = g[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = h[j][i];
    Dijkstra(1, sid1, af1), Dijkstra(n, sidn, afn);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = h[i][j];
    memcpy(h, g, sizeof(g));
    for (int i = 1; i <= m; i++)
    {
        int tmpa = g[u[i]][v[i]], tmpb = g[v[i]][u[i]];
        g[u[i]][v[i]] = f[u[i]][v[i]];
        g[v[i]][u[i]] = min(g[v[i]][u[i]], c[i]);

        int p = 0;
        if (fa1[v[i]] != u[i] || dis1[u[i]] + c[i] != dis1[v[i]])
            p = min(dis1[n], dis1[v[i]] + c[i] + sidn[u[i]]);
        else
            Dijkstra(1, dist, fat), p = dist[n];
        int q = 0;
        if (fan[v[i]] != u[i] || disn[u[i]] + c[i] != disn[v[i]])
            q = min(disn[1], disn[v[i]] + c[i] + sid1[u[i]]);
        else
            Dijkstra(n, dist, fat), q = dist[1];

        g[u[i]][v[i]] = tmpa;
        g[v[i]][u[i]] = tmpb;
        res = min(res, p + q + d[i]);
    }
    printf("%lld\n", res == inf ? -1 : res);
    return 0;
}
