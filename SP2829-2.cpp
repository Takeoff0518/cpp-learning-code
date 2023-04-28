#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#ifdef WIN32
#define TAT "%I64d"
#else
#define TAT "%lld"
#endif
#define int64 long long

using namespace std;
const int mode = 1e9;
int n, m, a[110], f[2][32768 + 5];

#define inc(x, y) x + y <= mode ? x + y : x + y - mode;
void work()
{
    int Mv = (1 << m) - 1, v2 = 1 << (m - 1), opt1 = 0, opt2 = 1;
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int t = 1; t <= n; t++)
    {
        for (int i = 1; i <= m; i++, swap(opt1, opt2), memset(f[opt2], 0, sizeof(f[opt2])))
            for (int j = 0, j2 = 0; j <= Mv; j += 2, j2++)
                f[opt2][j | 1] = f[opt1][j2],
                f[opt2][j] = (f[opt1][j2] + f[opt1][j2 | v2])%mode;
        for (int j = 0; j <= Mv; j++)
            if (j % a[t] == 0)
                f[opt1][j] = 0;
    }
    int ans = 0;
    for (int i = 0; i <= Mv; i++)
    {
        if (i % a[n])
            ans = (ans+ f[opt1][i])%mode;
    }
    cout << ans << endl;
}

int main()
{
    int T = 0;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        work();
    }
}