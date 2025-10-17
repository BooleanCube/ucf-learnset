#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

int n, m;
vector<vi> grid, vis;
int d[4] = {1, -1, 0, 0};

int valid(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    grid = vector<vi>(n, vi(m));
    vis = vector<vi>(n, vi(m));

    for(int i=0; i<n; i++) {
        string line; cin >> line;
        for(int j=0; j<m; j++) {
            grid[i][j] = line[j] - '0';
        }
    }

    deque<array<int, 3>> q;
    q.push_back({0, 0, 0});

    int ans = -1;
    
    while (!q.empty()) {
        auto [i, j, dd] = q.front();
        // cout << i << " " << j << " " << dd << endl;
        q.pop_front();

        if(i == n-1 && j == m-1) {
            ans = dd;
            break;
        }

        if(vis[i][j]) continue;
        vis[i][j] = 1;
        
        int k = grid[i][j];

        for(int z=0; z<4; z++) {
            int ni = i + d[z] * k, nj = j + d[3-z] * k;
            if(!valid(ni, nj) || vis[ni][nj]) continue;
            q.push_back({ni, nj, dd + 1});
        }
    }

    cout << ans << endl;
    return 0;
}