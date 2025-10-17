#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;


void solve() {
    int t; cin >> t;
    set<string> words; while(t--) {string s; cin >> s; words.insert(s);}
    int n, m; cin >> n >> m;
    vector<vector<pair<int, string>>> adj(n);
    for(int i=0; i<m; i++) {
        int u, v; string s; cin >> u >> v >> s;
        adj[u].push_back({v, s});
        adj[v].push_back({u, s});
    }

    deque<int> q;
    vector<int> vis(n);
    q.push_back(0);

    int ans = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();

        if(u == n-1) {
            cout << 1 << endl;
            return;
        }

        if(vis[u]) continue;
        vis[u] = 1;

        for(auto [v, w] : adj[u]) {
            if(vis[v] || words.count(w)) continue;
            q.push_back(v);
        }
    }

    cout << 0 << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}