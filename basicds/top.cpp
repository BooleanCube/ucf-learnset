#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    set<string> stack;
    int prev = -1;
    for(int i=0; i<n; i++) {
        if(stack.count(a[i]) < 1) stack.insert(a[i]);
        else stack.erase(a[i]);
        if(stack.count(b[i]) < 1) stack.insert(b[i]);
        else stack.erase(b[i]);
        if(stack.size() == 0) {
            cout << i-prev << endl;
            prev = i;
        }
    }
    return 0;
}