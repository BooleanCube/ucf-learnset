#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc = 0;
    while(++tc) {
        vector<stack<int>> stacks;
        string s; cin >> s;
        int n = s.size();
        if(s == "end") break;
        stack<int> fs; fs.push(s[0]);
        stacks.push_back(fs);
        for(int i=1; i<n; i++) {
            char cur = s[i];
            bool added = 0;
            for(int j=0; j<stacks.size(); j++) {
                if(stacks[j].top() >= cur) {
                    stacks[j].push(cur);
                    added = 1;
                    break;
                }
            }
            if(!added) {
                stack<int> ss;
                ss.push(cur);
                stacks.push_back(ss);
            }
        }
        cout << "Case " << tc << ": " << stacks.size() << endl;
    }
    return 0;
}