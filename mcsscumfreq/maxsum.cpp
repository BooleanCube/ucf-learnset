#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<vector<int>> ps(n+1, vector<int>(n));
        for(int i=1; i<=n; i++) {
            for(int j=0; j<n; j++) {
                cin >> ps[i][j];
                ps[i][j] += ps[i-1][j];
            }
        }
        int ans = LLONG_MIN;
        for(int i=1; i<=n; i++) {
            for(int j=i; j<=n; j++) {
                int mx = LLONG_MIN;
                int cur = 0;
                for(int k=0; k<n; k++) {
                    cur += ps[j][k]-ps[i-1][k];
                    mx = max(mx, cur);
                    cur = max(0LL, cur);
                }
                ans = max(ans, mx);
            }
        }
        cout << ans << endl;
    }
}