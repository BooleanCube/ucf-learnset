#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    vector<int> ps(1000002);
    for(int i=1; i<1000001; i++)
        ps[i] = ps[i-1] + ((int)(sqrt(i)) == sqrt(i));
    while(tc--) {
        int a, b; cin >> a >> b;
        cout << b-a-(ps[b]-ps[a-1])+1 << endl;
    }
    return 0;
}