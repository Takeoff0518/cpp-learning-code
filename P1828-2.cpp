#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define N 805
#define M 1500
#define INF 0x3f3f3f3f
using namespace std;
int vis[N], n, m, p;
int dis[N], tot, ans = INF;
int head[N], sum;
int id[500000];
struct edge
{
    int next, to, dis;
} e[M];
struct node
{
    int dis, pos;
    bool operator<(const node &x) const
    {
        return x.dis < dis;
    }
};
priority_queue<node> q;
inline void add(int x, int y, int w)
{
    e[++tot].to = y;
    e[tot].next = head[x];
    head[x] = tot;
    e[tot].dis = w;
}
void dijkstra(int s)
{ 
    for (int i = 1; i <= p; ++i)
        dis[i] = INF;
    memset(vis, 0, sizeof(vis));
    dis[s] = 0, q.push((node){0, s});
    while (!q.empty())
    {
        node tmp = q.top();
        q.pop();
        int x = tmp.pos;
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = head[x]; i; i = e[i].next)
        {
            int y = e[i].to;
            if (dis[y] > dis[x] + e[i].dis)
            {
                dis[y] = dis[x] + e[i].dis;
                if (!vis[y])
                    q.push((node){dis[y], y});
            }
        }
    }
}
int main()
{
    scanf("%d %d %d", &n, &p, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &id[i]);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w; 
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    for (int i = 1; i <= p; ++i)
    {
        dijkstra(i);
        sum = 0;
        for (int j = 1; j <= n; ++j)
            sum += dis[id[j]];
        ans = min(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}
