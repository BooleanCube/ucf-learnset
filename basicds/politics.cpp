#include <bits/stdc++.h>
using namespace std;

int main() {
    while(1) {
        int n, m; cin >> n >> m;
        if(n == 0 && m == 0) break;
        map<string, int> candidates;
        for(int i=0; i<n; i++) {
            string name; cin >> name;
            candidates[name] = i;
        }
        vector<tuple<int, int, string>> members;
        vector<tuple<int, int, string>> weirdos;
        map<string, int> wcandidates;
        for(int i=0; i<m; i++) {
            string name, candidate; cin >> name >> candidate;
            if(candidates.count(candidate) < 1) {
                if(wcandidates.count(candidate) < 1) wcandidates[candidate] = i;
                weirdos.push_back(make_tuple(wcandidates[candidate], i, name));
            } else
                members.push_back(make_tuple(candidates[candidate], i, name));
        }
        sort(members.begin(), members.end());
        sort(weirdos.begin(), weirdos.end());
        for(auto member : members) cout << get<2>(member) << endl;
        for(auto weirdo : weirdos) cout << get<2>(weirdo) << endl;
    }
    return 0;
}