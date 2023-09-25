#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> freq;
    int mx = 0;
    for(int i=0; i<n; i++) {
        string name; cin >> name;
        if(freq.count(name) < 1) freq[name] = 0;
        freq[name]++;
        mx = max(mx, freq[name]);
    }
    vector<string> winners;
    for(auto val : freq)
        if(val.second == mx)
            winners.push_back(val.first);
    sort(winners.begin(), winners.end());
    for(string name : winners) cout << name << endl;
    return 0;
}