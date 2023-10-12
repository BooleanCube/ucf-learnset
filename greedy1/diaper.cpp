#include <bits/stdc++.h>
using namespace std;

int ceil(int a, int b) {
    return a/b + (int)(a%b > 0);
}

int main() {
    int tc; cin >> tc;
    for(int tcn=1; tcn<=tc; tcn++) {
        int n, d; cin >> n >> d;
        vector<tuple<int, double, int>> diapers(d);
        for(int i=0; i<d; i++) {
            int D, C; double P; cin >> D >> P >> C;
            diapers[i] = make_tuple(D, P, C);
        }
        vector<int> poos(n);
        int sum = 0, mx = 0;
        for(int i=0; i<n; i++) {
            int poo; cin >> poo;
            poos[i] = poo;
            sum += poo;
            mx = max(mx, poo);
        }
        double ans = 1e9;
        int box = 0;
        for(int i=0; i<d; i++) {
            int D = get<0>(diapers[i]);
            double P = get<1>(diapers[i]);
            int C = get<2>(diapers[i]);
            if(mx > C) continue;
            int dipes = 0;
            int cur = 0;
            for(int j=0; j<n; j++) {
                if(cur + poos[j] <= C) cur += poos[j];
                else {
                    cur = poos[j];
                    dipes++;
                }
            }
            if(cur) dipes++;
            double curp = P*ceil(dipes, D);
            if(curp < ans) {
                ans = curp;
                box = i+1;
            }
        }
        cout << fixed << setprecision(2);
        printf("Diaper Scenario #%d: Buying box %d, you spend $%.2f.\n", tcn, box, ans);
    }
    return 0;
}