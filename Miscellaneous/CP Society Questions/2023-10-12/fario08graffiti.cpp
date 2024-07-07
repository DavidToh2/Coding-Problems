#include <bits/stdc++.h>
using namespace std;

int main() {
    int L; cin >> L;
    vector<vector<int>> v(L, vector<int>(3, 0));

    for (int i=0; i<L; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    vector<int> s;
    for (int c=0; c<L-1; c++) {
        int a = v[c][0] + v[c][1] + v[c+1][0] + v[c+1][1];
        int b = v[c][1] + v[c][2] + v[c+1][1] + v[c+1][2];
        s.emplace_back(max(a, b));
    }

    vector<int> sol(L, 0);
    sol[0] = 0;
    sol[1] = max(s[0], 0);
    sol[2] = max({s[0], s[1], 0});
    for (int i=3; i<L; i++) {
        sol[i] = max({s[i-1] + sol[i-2], s[i-2] + sol[i-3], sol[i-2], sol[i-3]});
    }

    cout << sol[L-1];
}