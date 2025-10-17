#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
#define f first
#define s second
#define sp <<" "<<
#define endl "\n" // remove when debugging
const int INF = 2e9;

struct FordFulkerson {
    using vp = vector<pii>;
    const int n, src, sink;
    vector<map<int, int>> edges;
    FordFulkerson(int N, int S, int T) : n(N), src(S), sink(T) {
        edges = vector<map<int, int>>(n);
    }
    void addEdge(int u, int v, int cap) {
        edges[u][v] = cap;
    }
    int dfs(int u, vi &vis, int cap) {
        if(u == sink) return cap;
        if(vis[u]) return -1; vis[u] = 1;

        for(auto [v, w] : edges[u]) {
            if(vis[v] || w == 0) continue;

            int flow = dfs(v, vis, min(cap, w));

            if(flow == -1) continue;
            edges[u][v] -= flow;
            edges[v][u] += flow;
            return flow;
        }

        return -1;
    }
    int calc() {
        int flow = 0;
        while(1) {
            vi vis(n);
            int cur = dfs(src, vis, INF);
            if(cur == -1) break;
            flow += cur;
        }
        return flow;
    }
};

void solve() {
    string r, g; cin >> r >> g;
    int n = r.size(), m = g.size();

    FordFulkerson ff(n+m+2, 0, n+m+1);
    
    for(int i=1; i<=n; i++) ff.addEdge(0, i, 1);
    for(int i=1; i<=n; i++) {
        for(int j=n+1; j<=n+m; j++) {
            if(abs(r[i-1] - g[j-n-1]) < 3) continue;
            ff.addEdge(i, j, 1);
        }
    }
    for(int j=n+1; j<=n+m; j++) ff.addEdge(j, n+m+1, 1);

    cout << ff.calc() << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tc; cin >> tc;
    while(tc--) solve();

    return 0;
}
