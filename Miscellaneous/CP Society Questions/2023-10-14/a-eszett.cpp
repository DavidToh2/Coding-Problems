#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int l = s.length();
    int i = 0;
    vector<int> s_pos;
    while (i < l) {
        cout << (char)(s[i] + 32);
        if (s[i] == 'S') {
            if (s[i+1] == 'S') {
                s_pos.emplace_back(i);
            }
        }
        i++;
    }
    cout << '\n';

    for (int j : s_pos) {
        for (int i=0; i<l; i++) {
            if (i == j) {
                cout << 'B';
            } else if (i != j+1) {
                cout << (char)(s[i] + 32);
            }
        }
        cout << '\n';
    }
}