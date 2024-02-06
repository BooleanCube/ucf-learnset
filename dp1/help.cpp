#include <bits/stdc++.h>
using namespace std;

int n, W;
vector<vector<int>> DP;
vector<array<int, 2>> tasks;

int knapsack(int idx, int wt) {
    if(wt > W) return -1e9;
    if(idx == n) return 0;
    if(DP[idx][wt] != -1) return DP[idx][wt];
    DP[idx][wt] = max(knapsack(idx+1, wt+tasks[idx][0])+tasks[idx][1], knapsack(idx+1, wt));
    return DP[idx][wt];
}

int main() {
    int tc; cin >> tc;
    for(int tcn=1; tcn<=tc; tcn++) {
        cin >> n >> W;
        DP = vector<vector<int>>(n, vector<int>(W+1, -1));
        tasks = vector<array<int, 2>>(n);
        for(int i=0; i<n; i++) cin >> tasks[i][0] >> tasks[i][1];
        cout << "Day #" << tcn << ": " << knapsack(0, 0) << endl;
    }
    return 0;
}