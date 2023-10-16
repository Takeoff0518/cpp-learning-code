#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 20;
const int INF = 0x3f3f3f3f;

int n, tA[MAXN], tB[MAXN], bestTime;
vector<int> currentA, currentB;

void dfs(int task, int timeA, int timeB) {
    if (task == n) {
        bestTime = min(bestTime, max(timeA, timeB));
        return;
    }

    // Try scheduling the task on machine A
    currentA.push_back(task);
    dfs(task + 1, timeA + tA[task], timeB);
    currentA.pop_back();

    // Try scheduling the task on machine B
    currentB.push_back(task);
    dfs(task + 1, timeA, timeB + tB[task]);
    currentB.pop_back();
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tA[i] >> tB[i];
    }

    bestTime = INF;
    dfs(0, 0, 0);

    cout << bestTime << endl;
    return 0;
}

