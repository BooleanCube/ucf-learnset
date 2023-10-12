#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b; cin >> n >> a >> b;
    int ans = 0;
    priority_queue<pair<int, int>> pq;
    vector<int> da(n+1), db(n+1), k(n+1);
    for(int i=0; i<=n; i++) {
        cin >> k[i] >> da[i] >> db[i];
        if(k[i]+da[i]+db[i] == 0) break;
        pq.push(make_pair(db[i]-da[i], k[i]));
        ans += db[i]*k[i];
    }
    cout << ans << endl;
    while(a && pq.size() && pq.top().first >= 0) {
        pair<int, int> cur = pq.top(); pq.pop();
        if(cur.second > a) cur.second = a;
        ans -= cur.first * cur.second;
        a -= cur.second;
    }
    cout << ans << endl;
    return 0;
}