#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

void backtrack(vector<pair<int, int>>& coords, map<int, set<int>>& blocked, set<int>& vis, int cur, int cnt, int n, double path, double& ans) {
    if(path > ans) return;
    if(cnt == n) {
        ans = min(ans, path);
        return;
    }
    vis.insert(cur);
    for(int i=0; i<n; i++) {
        if(blocked[cur].count(i) || vis.count(i)) continue;
        double dist = hypot(coords[i].f-coords[cur].f, coords[i].s-coords[cur].s);
        backtrack(coords, blocked, vis, i, cnt+1, n, path+dist, ans);
    }
    vis.erase(cur);
}

int main() {
    cout << fixed << setprecision(3);
    int tc; cin >> tc;
    for(int tcn=1; tcn<=tc; tcn++) {
        int r, b; cin >> r >> b;
        map<int, set<int>> blocked;
        vector<pair<int, int>> coords(r);
        for(int i=0; i<r; i++) cin >> coords[i].f >> coords[i].s;
        for(int i=0; i<b; i++) blocked[i] = set<int>();
        for(int i=0; i<b; i++) {
            int x, y; cin >> x >> y;
            blocked[x-1].insert(y-1);
            blocked[y-1].insert(x-1);
        }
        double ans = INT32_MAX;
        set<int> vis = set<int>();
        for(int i=0; i<r; i++) {
            vis.insert(i);
            backtrack(coords, blocked, vis, i, 1, r, hypot(coords[i].f, coords[i].s), ans);
            vis.erase(i);
        }
        cout << "Vacation #" << tcn << ":" << endl;
        if(ans < INT32_MAX) cout << "Jimmy can finish all of the rides in " << ans+120.0*r << " seconds." << endl;
        else cout << "Jimmy should plan this vacation a different day." << endl;
        cout << endl;
    }
    return 0;
}