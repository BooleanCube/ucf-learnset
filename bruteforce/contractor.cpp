#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long

void backtrack(vector<pair<int, int>>& jobs, ll cds, ll csum, int n, int d, int cur, ll& ans) {
    if(cds > d) return;
    ans = max(ans, csum);
    for(int i=cur+1; i<n; i++) {
        backtrack(jobs, cds+jobs[i].f, csum+jobs[i].s, n, d, i, ans);
    }
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        int n, d; cin >> n >> d;
        vector<pair<int, int>> jobs(n);
        set<int> vis = set<int>();
        for(int i=0; i<n; i++) cin >> jobs[i].f >> jobs[i].s;
        ll ans = 0;
        backtrack(jobs, 0, 0, n, d, -1, ans);
        cout << ans << endl;
    }
    return 0;
}