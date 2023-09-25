#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n, t; cin >> n >> t;
    vector<pair<string, ll>> lectures(n);
    for(int i=0; i<n; i++)
        cin >> lectures[i].first >> lectures[i].second;
    ll lo = 1, hi = 1e5+7;
    while(lo <= hi) {
        ll rooms = lo + (hi-lo)/2;
        priority_queue<ll, vector<ll>, greater<ll>> nv;
        for(int i=0; i<rooms; i++) nv.push(0);
        ll time = 0;
        for(auto lecture : lectures) {
            int vac = nv.top(); nv.pop();
            nv.push(vac+lecture.second);
            time = max(time, vac+lecture.second);
        }
        if(time <= t) hi = rooms-1;
        else lo = rooms+1;
    }
    int rooms = lo;
    cout << rooms << "\n";
    vector<tuple<string, ll, ll>> ans;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> nv;
    for(int i=0; i<rooms; i++) nv.push(make_pair(0, i));
    ll time = 0;
    for(auto lecture : lectures) {
        ll vac = nv.top().first, room = nv.top().second; nv.pop();
        nv.push(make_pair(vac+lecture.second, room));
        ans.push_back(make_tuple(lecture.first, room, vac));
    }
    sort(ans.begin(), ans.end());
    for(tuple<string, ll, ll> lecture : ans) {
        cout << get<0>(lecture) << " " << 
                get<1>(lecture) << " " << 
                get<2>(lecture) << "\n";
    }
    return 0;
}