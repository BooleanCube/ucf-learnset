#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<array<int, 3>> hl(0), vl(0);
        for(int i=0; i<n; i++) {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            if(x1 == x2) vl.push_back({min(y1, y2), max(y1, y2), x1});
            if(y1 == y2) hl.push_back({min(x1, x2), max(x1, x2), y1});
        }
        int src = n, sink = src+1, H = hl.size();
        Dinic graph(n+2);
        for(int i=0; i<H; i++) {
            graph.addEdge(src, i, 1);
            for(int j=0; j<vl.size(); j++) {
                if(vl[j][0] <= hl[i][2] && vl[j][1] >= hl[i][2] && hl[i][0] <= vl[j][2] && hl[i][1] >= vl[j][2]) {
                    graph.addEdge(i, H+j, 1);
                }
            }
        }
        for(int j=0; j<vl.size(); j++) graph.addEdge(H+j, sink, 1);
        cout << n-graph.calc(src, sink) << endl;
    }
}