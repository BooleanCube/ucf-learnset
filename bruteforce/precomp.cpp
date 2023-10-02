#include <bits/stdc++.h>
using namespace std;

set<int> ans;

int digs(int num) {
    return (int)(log10(num))+1;
}

void backtrack(int cur, int n) {
    if(cur>0 && digs(cur)==n) {
        ans.insert(cur);
        return;
    }
    cur *= 10;
    for(int i=cur==0; i<10; i++) {
        if((cur+i)%digs(cur+i) == 0)
            backtrack(cur+i, n);
    }
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        ans = set<int>();
        int n; cin >> n;
        backtrack(0, n);
        for(int num : ans) cout << num << "\n";
    }
    return 0;
}