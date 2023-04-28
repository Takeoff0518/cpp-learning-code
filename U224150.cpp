#include <iostream>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    long long ans = -1;
    for (long long i = m; i <= n; i++) {
        if (m % i == 0) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}