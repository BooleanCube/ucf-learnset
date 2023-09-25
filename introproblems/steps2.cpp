#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--) {
        int m; double d; cin >> m >> d;
        double ans = 0;
        for(int i=0; i<m; i++) {
            double step; cin >> step;
            ans += d/step;
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}
