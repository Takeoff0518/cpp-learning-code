#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int inf = 233333333;

int n, a[N], f[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = inf; //开始全赋inf，否则转移取min时就会挂掉
    for (int i = 1; i <= n; i++)
        f[i][i] = 1; //直接取一个数，花费一个代价
    for (int i = 1; i < n; i++)
        f[i][i + 1] = 1 + (a[i] != a[i + 1]); //取两个数的情况，如果相等取一次就好了，否则取两次
    for (int len = 3; len <= n; len++)               //注意转移时需要先枚举区间长度
        for (int i = 1; len + i - 1 <= n; i++)
        {
            int j = len + i - 1; //计算区间左右端点
            if (a[i] == a[j])
                f[i][j] = f[i + 1][j - 1];
            for (int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]); //转移
        }
    printf("%d", f[1][n]);

    return 0;
}