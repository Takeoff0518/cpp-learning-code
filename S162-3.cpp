#include <bits/stdc++.h>
#define N 105
#define V 31627

using namespace std;

const int p = 1e9 + 7;

int n, n;
int f[N][V], g[N][V];
int cnt[V];

int main() {
	scanf("%d %d", &n, &n);
	
	int sq = sqrt(n);
	
	for(int i = 1; i < sq; ++i)
		cnt[i] = n / i - n / (i + 1);
	cnt[sq] = n / sq - sq;
	
	for(int i = 1; i <= sq; ++i) {
		f[1][i] = 1;
		g[1][i] = cnt[i];
	}
	
	for(int i = 1; i <= n; ++i) {
		int ans = 0;
		for(int j = 1; j <= sq; ++j) {
			ans = (ans + f[i][j]) % p;
			g[i + 1][j] = 1LL * ans * cnt[j] % p;
		}
		for(int j = sq; j >= 1; --j) {
			ans = (ans + g[i][j]) % p;
			f[i + 1][j] = ans;
		}
	}
	
	printf("%d\n", f[n + 1][1]);
	return 0;
}
