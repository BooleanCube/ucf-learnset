#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

int dxs[6] = {1, -1, 0, 0, 0, 0};
int dys[6] = {0, 0, 1, -1, 0, 0};
int dzs[6] = {0, 0, 0, 0, 1, -1};

void dfs(vector<vii>& space, vector<vii>& vis, int x, int y, int z, int n) {
    vis[x][y][z] = 1;
    for(int i=0; i<6; i++) {
        int dx = dxs[i], dy = dys[i], dz = dzs[i];
        if(x+dx < 0 || x+dx >= n) continue;
        if(y+dy < 0 || y+dy >= n) continue;
        if(z+dz < 0 || z+dz >= n) continue;
        if(vis[x+dx][y+dy][z+dz]) continue;
        if(space[x+dx][y+dy][z+dz])
            dfs(space, vis, x+dx, y+dy, z+dz, n);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vii> space(n, vii(n, vi(n)));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                cin >> space[i][j][k];
            }
        }
    }
    int q; cin >> q;
    for(int sn=1; sn<=q; sn++) {
        int x, y, z; cin >> x >> y >> z;
        if(!space[x][y][z]) {
            cout << "Simulation #" << sn << ", volume cleared is 0 cubic feet.\n\n";
            continue;
        }
        vector<vii> vis(n, vii(n, vi(n)));
        dfs(space, vis, x, y, z, n);
        int cnt = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<n; k++)
                    cnt += vis[i][j][k];
        cout << "Simulation #" << sn << ", volume cleared is " << cnt << " cubic feet.\n\n";
    }
    return 0;
}