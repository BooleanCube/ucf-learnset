#include <bits/stdc++.h>
using namespace std;

//#define endl "\n"

set<string> ans;
set<int> vowels;

void backtrack(string cur, int s, int n) {
    if(s > 42) return;
    if(cur.size() == n) {
        if(s == 42) {
            cur = cur.substr(0, n-2)+cur[n-1]+cur[n-2];
            ans.insert(cur);
        }
        return;
    }
    int start = 'z';
    if(cur.size()) start = cur[cur.size()-1]-1;
    for(int i=start; i>='a'+(n-cur.size()); i--) {
        if(vowels.count(i)) continue;
        backtrack(cur+(char)(i), s+(i-'a')+1, n);
    }
}

int main() {
    for(int chr : "aeiouy") vowels.insert(chr);
    while(1) {
        int n; cin >> n;
        if(n == 42) {
            cout << "The answer to life, the universe and everything!" << endl;
            break;
        }
        ans = set<string>();
        backtrack("", 0, n);
        cout << "XKCD-like name(s) of length: " << n << endl;
        if(ans.size() == 0) cout << "Mostly Harmless" << endl;
        for(string s : ans)
            cout << s << endl;
    }
    return 0;
}