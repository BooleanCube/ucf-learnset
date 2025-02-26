#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid(7, vector<int>(7));
vector<vector<int>> board(7, vector<int>(7));
int starCnt = 0;
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {0, 1, -1, 0, 1, -1, -1, 1};

bool valid(int i, int j) {
    return 0 <= i && i < 7 && 0 <= j && j < 7;
}

int backtrack(int i, int j) {
    // cout << i << " " << j << " " << starCnt << endl;
    if(starCnt > 10) return 0;
    
    int flag = 0;
    for(int k=0; k<i-2; k++) {
        for(int l=0; l<7; l++) {
            // cout << grid[i][j] << " ";
            if(grid[k][l] > 0 && grid[k][l] < 9) flag = 1;
        }
        // cout << endl;
    }
    if(flag) return 0;
    
    if(i >= 7) {
        int flag = 0;
        for(int k=0; k<7; k++) {
            for(int l=0; l<7; l++) {
                // cout << grid[i][j] << " ";
                if(grid[k][l] > 0 && grid[k][l] < 9) flag = 1;
            }
            // cout << endl;
        }
        return !flag && starCnt == 10;
    }

    if(grid[i][j] == 9) {
        int flag = 0;
        for(int k=0; k<8; k++) {
            int di = i+dx[k], dj = j+dy[k];
            if(!valid(di, dj)) continue;
            if(grid[di][dj] == 0) flag = 1;
        }
        if(flag) {
            int ni = i, nj = j + 1;
            if(nj >= 7) ni++, nj = 0;
            if(backtrack(ni, nj)) return 1;

            return 0;
        }

        grid[i][j] = -1;
        for(int k=0; k<8; k++) {
            int di = i+dx[k], dj = j+dy[k];
            if(!valid(di, dj)) continue;
            if(grid[di][dj] > 0 && grid[di][dj] < 9) grid[di][dj]--;
        }
        starCnt++;

        int ni = i, nj = j + 1;
        if(nj >= 7) ni++, nj = 0;
        if(backtrack(ni, nj)) return 1;

        grid[i][j] = 9;
        for(int k=0; k<8; k++) {
            int di = i+dx[k], dj = j+dy[k];
            if(!valid(di, dj)) continue;
            if(grid[di][dj] >= 0 && grid[di][dj] < 8) grid[di][dj]++;
        }
        starCnt--;
    }

    int ni = i, nj = j + 1;
    if(nj >= 7) ni++, nj = 0;
    if(backtrack(ni, nj)) return 1;

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for(int tcn=1; tcn<=t; tcn++) {
        starCnt = 0;
        for(int i=0; i<7; i++) {
            string s; cin >> s;
            for(int j=0; j<7; j++) {
                if(s[j] == '.') board[i][j] = grid[i][j] = 9;
                else board[i][j] = grid[i][j] = s[j] - '0';
            }
        }
        cout << "Tentaizu Board #" << tcn << ":" << endl;
        if(!backtrack(0, 0)) {
            assert(1 == 2); // lmao no
        }
        for(int i=0; i<7; i++) {
            for(int j=0; j<7; j++) {
                if(grid[i][j] == 9) cout << '.';
                else if(grid[i][j] == -1) cout << '*';
                else cout << board[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}