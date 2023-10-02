#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int target = 0;

void backtrack(vector<int>& hexa, vector<int>& perm, vector<bool>& vis, int cur) {
    int exact = -1;
    if(cur == 4) {
        target = perm[0]+perm[1]+perm[2]+perm[3];
    } else if(cur == 6) {
        exact = max(target-perm[0]-perm[4]-perm[5], 0);
    } else if(cur == 8) {
        exact = max(target-perm[3]-perm[6]-perm[7], 0);
    } else if(cur == 10) {
        exact = max(target-perm[9]-perm[4]-perm[1], 0);
    } else if(cur == 11) {
        exact = max(target-perm[9]-perm[5]-perm[7], 0);
        if(exact != target-perm[10]-perm[2]-perm[8]) exact = -2;
    } else if(cur == 12) {
        ans++;
        return;
    }
    if(cur < 12) {
        if(perm[cur]) {
            backtrack(hexa, perm, vis, cur+1);
        } else {
            for(int i=0; i<12; i++) {
                if(vis[i]) continue;
                if(exact == -1 || hexa[i] == exact) {
                    vis[i] = 1;
                    perm[cur] = hexa[i];
                    backtrack(hexa, perm, vis, cur+1);
                    vis[i] = 0;
                }
            }
            perm[cur] = 0;
        }
    }
}

int main() {
    while(1) {
        ans = 0;
        vector<int> hexa(12);
        int s = 0;
        for(int i=0; i<12; i++) {
            cin >> hexa[i];
            s += hexa[i];
        }
        if(s == 0) break;
        vector<int> perm(12);
        vector<bool> vis(12, 0);
        perm[0] = hexa[0];
        vis[0] = 1;
        backtrack(hexa, perm, vis, 0);
        cout << ans << endl;
    }
    return 0;
}
