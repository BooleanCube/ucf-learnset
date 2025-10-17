#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sp <<" "<<
#define endl '\n'
#define afr(x) for(auto &u : x)
#define frn(n) for(int i=0; i<n; i++)
using vi = vector<int>;
using pii = pair<int, int>;

void solve() {
    int n, s; cin >> n >> s;
    vi val(s); afr(val) cin >> u;
    vector<vi> g(s+1);
    frn(n) {
        int u, m; cin >> u >> m;
        for(int j=0; j<m; j++) {
            int v; cin >> v;
            g[v].push_back(u);
            // g[u].push_back(v);
        }
    }

    vi vis(s+1);
    deque<int> q; q.push_back(1);
    while(!q.empty()) {
        int u = q.front(); q.pop_front();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int v : g[u]) {
            if(vis[v]) continue;
            q.push_back(v);
        }
    }

    int mx = -1;
    for(int i=1; i<=s; i++) if(vis[i]) mx = max(mx, val[i-1]);

    cout << mx << endl;
}

signed main() {
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}