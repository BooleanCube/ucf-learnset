#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x),end(x)

int main() {
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        vector<int> fingers(5); fingers[0] = 1;
        int ans = 0;
        for(int i=0; i<n; i++) {
            int cur = nums[i], idx = 5;
            while(--idx > cur) {
                if(fingers[idx]) {
                    fingers[idx] = 0;
                    ans++;
                }
            }
            if(!fingers[cur]) {
                fingers[cur] = 1;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}