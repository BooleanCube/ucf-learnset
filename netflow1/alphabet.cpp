#include <bits/stdc++.h>
using namespace std;

vector<set<int>> edges;
int src, sink, found, ans = 0;

int dfs(int cur, vector<int>& vis) {
    if(vis[cur]) return 0;
    vis[cur] = 1;
    if(cur == sink) {
        found = 1;
        ans++;
        return 1;
    }
    for(int nbr : edges[cur]) {
        if(vis[nbr]) continue;
        dfs(nbr, vis);
        if(found) {
            edges[cur].erase(edges[cur].lower_bound(nbr));
            edges[nbr].insert(cur);
            return 1;
        }
    }
    return 0;
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        string red, green; cin >> red >> green;
        int n = red.size(), m = green.size();
        vector<char> nodes(n+m);
        edges = vector<set<int>>(n+m+2);
        src = n+m, sink = src+1, ans = 0;
        for(int i=0; i<n; i++) nodes[i] = red[i];
        for(int i=n; i<n+m; i++) nodes[i] = green[i-n];
        for(int i=0; i<n; i++) {
            edges[src].insert(i);
            for(int j=0; j<m; j++) {
                if(abs(red[i]-green[j]) < 3) continue;
                edges[i].insert(n+j);
            }
        }
        for(int i=n; i<n+m; i++) edges[i].insert(sink);
        vector<int> vis(n+m+2);
        while(dfs(src, vis)) {
            vis = vector<int>(n+m+2);
            found = 0;
        }
        cout << ans << endl;
    }
    return 0;
}