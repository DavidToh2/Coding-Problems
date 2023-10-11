#include <bits/stdc++.h>
using namespace std;

bool checkAdjacency(vector<vector<int>> &v, int i, int j, int n, int m, int t) {
    if (i == 0 || i == n-1 || j == 0 || j == m-1) {
        return true;
    } else if (v[i][j-1] == t || v[i][j+1] == t || v[i-1][j] == t || v[i+1][j] == t){
        return true;
    } else {
        return false;
    }
}

int main() {
    int n, m, t = 0;
    cin >> n >> m;
    string s;
    vector<vector<int>> v(n, vector<int>(m, 0));
    while (cin >> s) {
        for (int j=0; j<m; j++) {
            if (s[j] == 'T') {
                v[t][j] = -1;
            }
        }
        t++;
    }

    t = 0;

    bool isChanged = true;
    while (isChanged) {

        isChanged = false;

        // Iterate over the entire grid, focusing on the tree grids that have yet to be labelled.
        // For each as-yet labelled grid, if it has at least one adjacent cell labelled with t, then label it with t+1.
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (v[i][j] == -1) {
                    if (checkAdjacency(v, i, j, n, m, t)) {
                        v[i][j] = t+1;
                        isChanged = true;
                    }
                }
            }
        }

        t++;
    }
    // The final number of rings is t.

    if (t < 10) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (v[i][j]) {
                    cout << "." << v[i][j];
                } else {
                    cout << "..";
                }
            }
            cout << '\n';
        }
    } else {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (v[i][j]) {
                    if (v[i][j] < 10) {
                        cout << ".." << v[i][j];
                    } else {
                        cout << "." << v[i][j];
                    }
                } else {
                    cout << "...";
                }
            }
            cout << '\n';
        }
    }
}