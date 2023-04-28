#include<bits/stdc++.h>
#define N 1005
using namespace std;
int a[N];
#define val first
#define id second
int main() {
    int _;
    scanf("%d", &_);
    int n;
    for (int cas = 1; cas <= _; cas++) {
        if (cas == 1) {
            scanf("%d", &n);
            for (int i = 1; i <= n; i++) {
                scanf("%d", &a[i]);
            }
        } else {
            int k;
            scanf("%d", &k);
            while (k--) {
                int x, y;
                scanf("%d%d", &x, &y);
                a[x] = y;
            }
        }
        deque<pair<int, int> > q1, q2;
        for (int i = 1; i <= n; i++) {
            q1.push_back({a[i], i});
        }
        int ans;
        while (1) {
            if (q1.size() + q2.size() == 2) {
                ans = 1;
                break;
            }
            int stronger, idx, weaker;
            weaker = q1.front().val, q1.pop_front();
            if (q2.empty() || !q1.empty() && q1.back() > q2.back()) {
                stronger = q1.back().val,
                 idx = q1.back().id, q1.pop_back();
            } else {
                stronger = q2.back().val, idx = q2.back().id, q2.pop_back();
            }
            pair<int, int> newer = make_pair(stronger - weaker, idx);
            if (q1.empty() || q1.front() > newer) {
                ans = q1.size() + q2.size() + 2;  // 不吃
                int cnt = 0;
                while (1) {
                    cnt++;
                    if (q1.size() + q2.size() + 1 == 2) {
                        if (cnt % 2 == 0) ans--;
                        break;
                    }
                    if (q2.empty() || !q1.empty() && q1.back() > q2.back()) {
                        stronger = q1.back().val, 
                        idx = q1.back().id, 
                        q1.pop_back();
                    } else {
                        stronger = q2.back().val, 
                        idx = q2.back().id, 
                        q2.pop_back();
                    }
                    newer = {stronger - newer.val, idx};
                    if ((q1.empty() || newer < q1.front()) && (q2.empty() || newer < q2.front())) {
                        ;
                    } else {
                        if (cnt % 2 == 0) ans--;
                        break;
                    }
                }
                break;
            } else {
                q2.push_front(newer);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
