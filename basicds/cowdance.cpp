#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n, t; cin >> n >> t;
    vector<int> cows(n);
    for(int i=0; i<n; i++) cin >> cows[i];
    int lo = 1, hi = 1e5+5;
    while(lo <= hi) {
        int k = lo+(hi-lo)/2;
        priority_queue<int, vector<int>, greater<int>> nv;
        for(int i=0; i<k; i++) nv.push(0);
        int time = 0;
        for(int cow : cows) {
            int vac = nv.top(); nv.pop();
            nv.push(vac+cow);
            time = max(time, vac+cow);
        }
        if(time <= t) hi = k-1;
        else lo = k+1;
    }
    cout << lo << endl;
    return 0;
}