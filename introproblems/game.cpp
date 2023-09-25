#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while(n--) {
        string dirs; cin >> dirs;
        int g = 0;
        int ans = 0;
        for(char c : dirs) {
            if(c == 'v') g++;
            else if(c == '^') g--;
            ans = max(ans, g);
        }
        cout << ans << endl;
    }
    return 0;
}
