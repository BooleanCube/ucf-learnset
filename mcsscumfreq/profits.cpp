#include <bits/stdc++.h>
using namespace std;

int main() {
    while(1) {
        int n; cin >> n;
        if(!n) break;
        vector<int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        int sum = 0, ans = INT32_MIN;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            ans = max(ans, sum);
            sum = max(0, sum);
        }
        cout << ans << endl;
    }
    return 0;
}