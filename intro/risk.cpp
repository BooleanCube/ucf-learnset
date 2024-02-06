#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        multiset<int> d;
        for(int i=0; i<n; i++) {
            int army; cin >> army;
            d.insert(army);
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for(int i=0; i<n; i++) {
            auto it = d.lower_bound(a[i]);
            if(it == d.end()) break;
            ans++;
            d.erase(it);
        }
        cout << ans << endl;
    }
    return 0;
}