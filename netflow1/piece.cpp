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

int adj[4] = {-1, 1, 0, 0};

int getId(int r, int c, int m) {
    return r*m + c;
}

bool valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int nmod(int a, int b) {
    while(a < 0) a += b;
    return a%b;
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        int n, m; cin >> n >> m;
        vector<string> grid(n);
        int N = n*m, B = 0, T = 0;
        for(int i=0; i<n; i++) {
            cin >> grid[i];
            for(char c : grid[i]) {
                if(c == 'B') { T++; B++; }
                if(c == 'W') T++;
            }
        }
        if(T != B*3) {
            cout << "NO\n";
            continue;
        }
        vector<bool> vis(N);
        Dinic graph(N+2);
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
                
        //     }
        // }
        int src = N, sink = N+1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 'B') {
                    int id = getId(i, j, m);
                    graph.addEdge(src, id, 1);
                    int inc = 0;
                    for(int k=0; k<4; k++) {
                        int x1 = i+adj[k], y1 = j+adj[3-k];
                        int x2 = i+adj[(k+1)%4], y2 = j+adj[nmod(3-k-1, 4)];
                        int ndy = adj[k] != 0 ? adj[k] : adj[(k+1)%4];
                        int ndx = adj[3-k] != 0 ? adj[3-k] : adj[nmod(3-k-1, 4)];
                        if(!valid(x1, y1, n, m)) continue;
                        if(!valid(x2, y2, n, m)) continue;
                        if(grid[x1][y1] != 'W' || grid[x2][y2] != 'W') continue;
                        int nbrId = getId(x1, y1, m);
                        graph.addEdge(id, nbrId, 1);
                        inc++;
                        if(vis[nbrId]) continue;
                        graph.addEdge(nbrId, sink, 1);
                        vis[nbrId] = 1;
                    }
                    // cout << inc << endl;
                }
            }
        }
        cout << (graph.calc(src, sink) == B ? "YES":"NO") << endl;
    }
    return 0;
}