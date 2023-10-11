#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; int i = 0;
    string s, line;
    getline(cin, s);
    getline(cin, s);
    n = stoi(s);
    vector<vector<string>> v(n, vector<string>());
    while (getline(cin, line)) {
        stringstream ss(line);
        while (getline(ss, s, ',')) {
            v[i].emplace_back(s);
        }
        i++;
    }

    int l = v[0].size();

    vector<vector<int>> vi(n, vector<int>(n, 0));
    // vi[a][b] is the number of changes required to transform input a to input b. (All zero-indexed)

    for (int a=0; a<n-1; a++) {
        for (int b=a+1; b<n; b++) {

            for (int j=0; j<l; j++) {
                if (v[a][j] != v[b][j]) {
                    vi[a][b]++;
                    vi[b][a]++;
                }
            }

        }
    }

    vector<int> vi_max(n);
    for (int a=0; a<n; a++) {
        int max = 0;
        for (int b=0; b<n; b++) {
            if (vi[a][b] > max) {
                max = vi[a][b];
            }
        }
        vi_max[a] = max;
    }

    int min = vi_max[0];
    for (int a=1; a<n; a++) {
        if (vi_max[a] < min) {
            min = vi_max[a];
        }
    }

    for (int a=0; a<n; a++) {
        if (vi_max[a] == min) {
            for (int j=0; j<l-1; j++) {
                cout << v[a][j] << ",";
            }
            cout << v[a][l-1] << '\n';
        }
    }
}