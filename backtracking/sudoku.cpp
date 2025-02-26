#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rows(10, vector<int>(10)), cols(10, vector<int>(10)), boxs(10, vector<int>(10));
vector<vector<int>> grid(9, vector<int>(9));

int boxidx(int i, int j) {
    return (i / 3) * 3 + (j / 3);
}

int backtrack(int i, int j) {
    if(i >= 9) return 1;
    if(grid[i][j] == 0) {
        vector<int> poss(10, 1);
        for(int k=1; k<=9; k++) {
            if(rows[i][k]) poss[k] = 0;
            if(cols[j][k]) poss[k] = 0;
            if(boxs[boxidx(i, j)][k]) poss[k] = 0;
        }
        int flag = 1;
        for(int k=1; k<=9; k++) {
            if(!poss[k]) continue;
            flag = 0;
            rows[i][k] = 1;
            cols[j][k] = 1;
            boxs[boxidx(i, j)][k] = 1;
            grid[i][j] = k;
            int ni = i, nj = j + 1;
            if(nj >= 9) ni++, nj = 0;
            if(backtrack(ni, nj)) return 1;
            grid[i][j] = 0;
            rows[i][k] = 0;
            cols[j][k] = 0;
            boxs[boxidx(i, j)][k] = 0;
        }
        if(flag) return 0;
    } else {
        int ni = i, nj = j + 1;
        if(nj >= 9) ni++, nj = 0;
        if(backtrack(ni, nj)) return 1;
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for(int tcn=1; tcn<=t; tcn++) {
        rows = vector<vector<int>>(10, vector<int>(10));
        cols = vector<vector<int>>(10, vector<int>(10));
        boxs = vector<vector<int>>(10, vector<int>(10));
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                cin >> grid[i][j];
        int flag = 0;
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(!grid[i][j]) continue;

                rows[i][grid[i][j]]++;
                if(rows[i][grid[i][j]] > 1) flag = 1;

                cols[j][grid[i][j]]++;
                if(cols[j][grid[i][j]] > 1) flag = 1;

                boxs[boxidx(i, j)][grid[i][j]]++;
                if(boxs[boxidx(i, j)][grid[i][j]] > 1) flag = 1;
            }
        }
        cout << "Test case " << tcn << ":\n";
        if(flag || !backtrack(0, 0)) {
            cout << "No solution possible.\n";
            cout << endl;
            continue;
        }
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                cout << grid[i][j] << " \n"[j==8];
        cout << endl;
    }
    return 0;
}