#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> sales(n);
        for(int i=0; i<n; i++) cin >> sales[i];
        int ans = 0;
        for(int c=0; c<10000; c++) {
            int leftover = 0;
            bool works = 1;
            for(int i : sales) {
                leftover += c-i;
                if(leftover < 0) {
                    works = 0;
                    break;
                }
            }
            if(works) {
                ans = c;
                break;
            }
        }
        int leftover = 0;
        int mx = -1;
        for(int i : sales) {
            leftover += ans-i;
            mx = max(mx, leftover);
        }
        cout << ans << " " << mx << endl;
    }
    return 0;
}
