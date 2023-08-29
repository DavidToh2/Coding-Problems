#include <bits/stdc++.h>
using namespace std;

int main() {
    string m; string n;
    getline(cin, m); getline(cin, n);
    int lm = m.length();
    int z = n.length() - 1;

    int zcount = 0;
    while (m[lm-1-zcount] == '0') {
        zcount++;
    }

    if (z < lm) {
        // No leading zeroes needed.
        cout << m.substr(0, lm-z);
        if (z > zcount) {
            cout << ".";
            cout << m.substr(lm-z, z-zcount);
        }
    } else {
        // Leading zeroes needed.
        cout << "0.";
        if (z > lm) {
            string r(z-lm, '0');
            cout << r;
        }
        cout << m.substr(0, lm-zcount);
    }
}