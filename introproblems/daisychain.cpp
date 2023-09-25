#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int tc; cin >> tc;
    while(tc--) {
        ll n, p, g; cin >> n >> p >> g;
        int e = n%g ? (p-1)*(n%g-1)+p : 0;
        cout << ((p-1)*(g-1)+p)*(n/g) + e << endl;
    }
    return 0;
}
