#include <bits/stdc++.h>
using namespace std;

int adj[4] = {1, -1, 0, 0};

void dfs(vector<string>& grid, vector<vector<int>>& vis, int x, int y, int n, int m) {
    vis[x][y] = 1;
    for(int i=0; i<4; i++) {
        int dx = adj[i], dy = adj[3-i];
        if(x+dx < 0 || x+dx >= n) continue;
        if(y+dy < 0 || y+dy >= m) continue;
        if(vis[x+dx][y+dy]) continue;
        if(grid[x+dx][y+dy] == '~')
            dfs(grid, vis, x+dx, y+dy, n, m);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    vector<vector<int>> vis(n, vector<int>(m));
    pair<int, int> start;
    for(int i=0; i<n; i++) {
        cin >> grid[i];
        for(int j=0; j<m; j++)
            if(grid[i][j] == 'X')
                start = make_pair(i, j);
    }
    dfs(grid, vis, start.first, start.second, n, m);
    int cnt = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cnt += vis[i][j];
    cout << cnt*5 << "\n";
}

int main() {
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}