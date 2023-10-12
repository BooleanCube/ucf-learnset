#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int tc; cin >> tc;
    while(tc--) {
        ll n; cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int i=0; i<n; i++) {
            int a; cin >> a;
            pq.push(a);
        }
        ll sum = 0;
        for(int i=0; i<n-1; i++) {
            int num = pq.top(); pq.pop();
            num += pq.top(); pq.pop();
            sum += num;
            pq.push(num);
        }
        cout << sum << endl;
    }
    return 0;
}