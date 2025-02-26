#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

int n, g;
vector<vector<int>> rows, cols, ans;
vector<vector<char>> grid;
map<char, pair<int, char>> ops;
map<char, vector<pair<int, int>>> gidx;
vector<pair<int, int>> inds;

void printans() {
    cout << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cout << ans[i][j];
        cout << endl;
    }
    cout << endl;
}

int backtrack(int idx, int val, int rem) {
    // cout << idx << " " << val << " " << rem << endl;
    if(idx == inds.size()) return 1;

    int i = inds[idx].first, j = inds[idx].second;
    char group = grid[i][j];
    int target = ops[grid[i][j]].first;
    char op = ops[grid[i][j]].second;
    // cout << i << " " << j << endl;

    if(!rem) {
        val = 0;
        rem = gidx[group].size();
    }
    else {
        if(val && op == '+') {
            int remVal = target - val;
            if(remVal <= 0) return 0;
            if(remVal > rem * n) return 0;
        } else if(val && op == '*') {
            if(target % val) return 0;
        }
    }

    int oval = val;

    vector<int> poss(n+1, 1); poss[0] = 0;
    for(int k=1; k<=n; k++) {
        if(rows[i][k]) poss[k] = 0;
        if(cols[j][k]) poss[k] = 0;
    }

    for(int k=n; k>=1; k--) {
        if(!poss[k]) continue;

        if(op == '*') {
            if(val == 0) val = k;
            else val *= k;
        }
        else if(op == '+') val += k;
        else if(op == '-') {
            val -= k;
            val = abs(val);
        }
        else if(op == '/') {
            if(val == 0) val = k;
            else if(val > k) {
                if(val % k) continue;
                val /= k;
            } else {
                if(k % val) continue;
                int tmp = val;
                val = k / tmp;
            }
        }
        else if(op == '.') val = k;
        ans[i][j] = k, rem--;

        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        if(!rem && val != target) {
            ans[i][j] = 0, rem++, val = oval;
            continue;
        }

        // cout << "passed" << endl;

        rows[i][k] = 1;
        cols[j][k] = 1;

        // cout << group << " " << i << " " << j << " " << k << " " << val << " " << target << " " << rem << endl;
        // printans();

        if(backtrack(idx+1, val, rem)) return 1;

        ans[i][j] = 0;
        rem++, val = oval;
        rows[i][k] = 0;
        cols[j][k] = 0;
    }
    
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tcn = 1;
    for(;;) {
        cin >> n;
        if(!n) break;
        cin >> g;
        rows = vector<vector<int>>(n+1, vector<int>(n+1));
        cols = vector<vector<int>>(n+1, vector<int>(n+1));
        grid = vector<vector<char>>(n, vector<char>(n));
        ans = vector<vector<int>>(n, vector<int>(n));
        gidx.clear(); ops.clear(); inds.clear();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> grid[i][j];
                gidx[grid[i][j]].push_back({i, j});
            }
        }
        for(auto &[gc, vc] : gidx)
            for(pair<int, int> &pt : vc)
                inds.push_back(pt);
        for(int i=0; i<g; i++) {
            char c; cin >> c;
            int num; cin >> num;
            char op; cin >> op;
            ops[c] = {num, op};
        }
        
        cout << "KenKen Puzzle #" << (tcn++) << ":\n";
        if(!backtrack(0, 0, gidx[grid[inds[0].first][inds[0].second]].size())) {
            assert(1 == 0); // mgiht cause runtime error
            continue;
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++)
                cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}