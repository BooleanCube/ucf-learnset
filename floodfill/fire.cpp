#include <bits/stdc++.h>
using namespace std;

void solve(int tcn) {
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    string works = "F."; long unsigned int npos = string::npos;
    for(int i=0; i<h; i++) cin >> grid[i];
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(grid[i][j] == 'V') {
                for(int k=i+1; k<h; k++) {
                    if(works.find(grid[k][j]) != npos) grid[k][j] = 'F';
                    else break;
                }
                bool left = 1, right = 1;
                for(int k=1; k<w; k++) {
                    if(i+k<h && j+k<w && right) {
                        if(works.find(grid[i+k][j+k]) != npos) {
                            grid[i+k][j+k] = 'F';
                            for(int l=i+k+1; l<h; l++) {
                                if(works.find(grid[l][j+k]) != npos) grid[l][j+k] = 'F';
                                else break;
                            }
                        }
                        else right = 0;
                    }
                    if(i+k<h && j-k>=0 && left) {
                        if(works.find(grid[i+k][j-k]) != npos) {
                            grid[i+k][j-k] = 'F';
                            for(int l=i+k+1; l<h; l++) {
                                if(works.find(grid[l][j-k]) != npos) grid[l][j-k] = 'F';
                                else break;
                            }
                        }
                        else left = 0;
                    }
                }
            }
            if(grid[i][j] == '^') {
                for(int k=i-1; k>=0; k--) {
                    if(works.find(grid[k][j]) != npos) grid[k][j] = 'F';
                    else break;
                }
                bool left = 1, right = 1;
                for(int k=1; k<w; k++) {
                    if(i-k>=0 && j+k<w && right) {
                        if(works.find(grid[i-k][j+k]) != npos) {
                            grid[i-k][j+k] = 'F';
                            for(int l=i-k-1; l>=0; l--) {
                                if(works.find(grid[l][j+k]) != npos) grid[l][j+k] = 'F';
                                else break;
                            }
                        }
                        else right = 0;
                    }
                    if(i-k>=0 && j-k>=0 && left) {
                        if(works.find(grid[i-k][j-k]) != npos) {
                            grid[i-k][j-k] = 'F';
                            for(int l=i-k-1; l>=0; l--) {
                                if(works.find(grid[l][j-k]) != npos) grid[l][j-k] = 'F';
                                else break;
                            }
                        }
                        else left = 0;
                    }
                }
            }
            if(grid[i][j] == '<') {
                for(int k=j-1; k>=0; k--) {
                    if(works.find(grid[i][k]) != npos) grid[i][k] = 'F';
                    else break;
                }
                bool left = 1, right = 1;
                for(int k=1; k<h; k++) {
                    if(i+k<h && j-k>=0 && left) {
                        if(works.find(grid[i+k][j-k]) != npos) {
                            grid[i+k][j-k] = 'F';
                            for(int l=j-k-1; l>=0; l--) {
                                if(works.find(grid[i+k][l]) != npos) grid[i+k][l] = 'F';
                                else break;
                            }
                        }
                        else left = 0;
                    }
                    if(i-k>=0 && j-k>=0 && right) {
                        if(works.find(grid[i-k][j-k]) != npos) {
                            grid[i-k][j-k] = 'F';
                            for(int l=j-k-1; l>=0; l--) {
                                if(works.find(grid[i-k][l]) != npos) grid[i-k][l] = 'F';
                                else break;
                            }
                        }
                        else right = 0;
                    }
                }
            }
            if(grid[i][j] == '>') {
                for(int k=j+1; k<w; k++) {
                    if(works.find(grid[i][k]) != npos) grid[i][k] = 'F';
                    else break;
                }
                bool left = 1, right = 1;
                for(int k=1; k<h; k++) {
                    if(i+k<h && j+k<w && left) {
                        if(works.find(grid[i+k][j+k]) != npos) {
                            grid[i+k][j+k] = 'F';
                            for(int l=j+k+1; l<w; l++) {
                                if(works.find(grid[i+k][l]) != npos) grid[i+k][l] = 'F';
                                else break;
                            }
                        }
                        else left = 0;
                    }
                    if(i-k>=0 && j+k<w && right) {
                        if(works.find(grid[i-k][j+k]) != npos) {
                            grid[i-k][j+k] = 'F';
                            for(int l=j+k+1; l<w; l++) {
                                if(works.find(grid[i-k][l]) != npos) grid[i-k][l] = 'F';
                                else break;
                            }
                        }
                        else right = 0;
                    }
                }
            }
        }
    }
    cout << "Map #" << tcn << ":\n";
    for(int i=0; i<h; i++)
        cout << grid[i] << "\n";
    cout << "\n";
}

int main() {
    int tc; cin >> tc;
    for(int tcn=1; tcn<=tc; tcn++) solve(tcn);
    return 0;
}