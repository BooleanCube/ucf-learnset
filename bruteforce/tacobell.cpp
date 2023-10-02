#include <bits/stdc++.h>
using namespace std;

int next_mask(int mask) {
    int c = mask & -mask, r = mask + c;
    return r | (((r ^ mask) >> 2) / c);
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        int n, m; cin >> n >> m;
        vector<string> food(n);
        for(int i=0; i<n; i++) cin >> food[i];
        sort(begin(food), end(food));
        vector<string> ans = vector<string>();
        for(int mask=(1<<m)-1; mask<(1<<n); mask=next_mask(mask)) {
            string out = "";
            for(int i=0; i<n; i++) {
                if((mask & (1<<i)) > 0)
                    out += food[i] + " ";
            }
            ans.push_back(out);
        }
        sort(begin(ans), end(ans));
        for(string line : ans) cout << line << endl;
        cout << endl;
    }
    return 0;
}