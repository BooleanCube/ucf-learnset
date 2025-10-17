#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<bool> vis(1000000, false);
        bool found = false;

        while (!q.empty()) {
            auto [cur, dep] = q.front();
            q.pop();

            if (cur == t) {
                found = true;
                cout << dep << endl;
                break;
            }

            if (vis[cur]) continue;
            vis[cur] = true;

            int next;

            next = (cur + a) % 1000000;
            if (!vis[next]) q.push({next, dep + 1});

            next = (1LL * cur * b) % 1000000;
            if (!vis[next]) q.push({next, dep + 1});

            next = (cur / c) % 1000000;
            if (!vis[next]) q.push({next, dep + 1});
        }

        if (!found) cout << -1 << endl;
    }

    return 0;
}
