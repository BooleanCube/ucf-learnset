#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int adj[4] = {1, -1, 0, 0};

bool dfs(vector<vector<int>>& ff, int x, int y, int r, int c, int cur) {
    if(ff[x][y] != 0) return false;
    ff[x][y] = cur;
    for(int i=0; i<4; i++) {
        int dx = adj[i], dy = adj[3-i];
        if(x+dx < 0 || x+dx >= r) continue;
        if(y+dy < 0 || y+dy >= c) continue;
        dfs(ff, x+dx, y+dy, r, c, cur);
    }
    return true;
}

void solve() {
    int r, c; cin >> r >> c;
    vector<string> grid(r);
    vector<vector<int>> ff(r, vector<int>(c));
    pair<int, int> pc, cc;
    for(int i=0; i<r; i++) {
        cin >> grid[i];
        for(int j=0; j<c; j++) {
            if(grid[i][j] == '#') ff[i][j] = -1;
            else if(grid[i][j] == 'P') pc = make_pair(i, j);
            else if(grid[i][j] == 'C') cc = make_pair(i, j);            
        }
    }
    int cur = 1;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(dfs(ff, i, j, r, c, cur)) cur++;
    cout << (ff[pc.f][pc.s]==ff[cc.f][cc.s] ? "yes" : "no") << "\n";
}

int main() {
    int tc; cin >> tc;
    while(tc--) solve();
}