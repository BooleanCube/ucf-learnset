#include <bits/stdc++.h>
using namespace std;

string encode(const vector<vector<int>>& x) {
    string result = "";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result += to_string(x[i][j]);
        }
    }
    return result;
}

vector<vector<int>> decode(const string& s) {
    vector<vector<int>> result(3, vector<int>(3));
    int idx = 0;
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 3; ++j) {
            result[idx][j] = s[i + j] - '0';
        }
        ++idx;
    }
    return result;
}

bool valid(int i, int j) {
    return i >= 0 && i < 3 && j >= 0 && j < 3;
}

map<string, int> memo;

void solve() {
    vector<vector<int>> a(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    
    cout << memo[encode(a)] << endl;
}

void precomp() {
    vector<vector<int>> a(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            a[i][j] = i * 3 + j + 1;
        }
    }
    a[2][2] = 0;

    deque<pair<int, string>> q;
    memo[encode(a)] = 0;
    q.push_back({0, encode(a)});

    int ans = -1;
    vector<int> dd = {1, -1, 0, 0};
    
    while (!q.empty()) {
        int pl = q.front().first;
        string cur = q.front().second;
        q.pop_front();
        
        vector<vector<int>> nxt = decode(cur);
        
        int i, j;
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 3; ++j) {
                if (nxt[i][j] == 0) {
                    break;
                }
            }
            if (j < 3) break;
        }
        
        for (int k = 0; k < 4; ++k) {
            int di = dd[k], dj = dd[3 - k];
            if (valid(i + di, j + dj)) {
                swap(nxt[i][j], nxt[i + di][j + dj]);
                
                string enc = encode(nxt);
                if (memo.count(enc) == 0) {
                    q.push_back({pl + 1, enc});
                    memo[enc] = pl + 1;
                }
                
                swap(nxt[i][j], nxt[i + di][j + dj]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    precomp();
    
    for (int i = 0; i < n; ++i) {
        solve();
    }
    
    return 0;
}
