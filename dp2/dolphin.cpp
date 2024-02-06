#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    for(int tcn=1; tcn<=tc; tcn++) {
        int n; cin >> n;
        vector<int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        vector<int> inc(n, 1), dec(n, 1);
        for(int i=0; i<n; i++) {
            for(int j=i-1; j>=0; j--) {
                if(nums[i] >= nums[j])
                    inc[i] = max(inc[i], inc[j]+1);
            }
        }
        reverse(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            for(int j=i-1; j>=0; j--) {
                if(nums[i] >= nums[j])
                    dec[i] = max(dec[i], dec[j]+1);
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) ans = max(ans, inc[i]+dec[n-i-1]-1);
        cout << "Case " << tcn << ":" << endl;
        cout << "Dynamo ate " << ans << " food pellet(s).\n";
        cout << endl;
    }
    return 0;
}