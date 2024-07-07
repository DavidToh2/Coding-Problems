#pragma GCC optimise("Ofast")
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

int main() {
    string s; cin >> s;
    int l = s.length();
    vector<vector<int>> v(26, vector<int>());

    for (int i=0; i<l; i++) {
        v[(char) s[i] - 97].emplace_back(i);
    }

    // for (int i=0; i<26; i++) {
    //     cout << "For letter " << (char) (i+97) << ": ";
    //     for (int j=0; j<v[i].size(); j++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    vector<int> vt(l + 1, 0);
    vector<int> vl(l + 1, 0);
    int c = 1;
    for (int i=0; i<26; i++) {
        for (int j=0; j<v[i].size(); j++) {
            vt[c] = v[i][j] + 1;
            vl[c] = i;
            c++;
            // Sorted letter no. c should be in unsorted position vt[c].
            // All indices start from 1.
        }
    }

    // for (int i=1; i<l+1; i++) {
    //     cout << vt[i] << " ";
    // }

    c = 0;
    for (int i=1; i<l+1; i++) {
        if (vt[i] == 0) {
            continue;
        } else {
            int j = i, k = vt[i];
            if (k == i) {
                continue;
            } else {
                vt[i] = 0;
                while (k != i) {
                    if (vl[i] == vl[k]) {
                        
                    } else if (vl[i] < vl[k]) {
                        cout << k << " " << i << endl;
                        int a = vl[i];
                        vl[i] = vl[k];
                        vl[k] = a;
                    } else {
                        cout << i << " " << k << endl;
                        int a = vl[i];
                        vl[i] = vl[k];
                        vl[k] = a;
                    }
                    j = k;
                    k = vt[k];
                    vt[j] = 0;
                }
            }
        }
    }

}


// ebcdbaceb
// abbbccdee
// cbbbcAdee 1 - 6
// cBbbcAdee 2 - 2
// cBcbBAdee 3 - 5
// cBceBAdeB 4 - 9
// cBCeBAdeB 5 - 3 (3 - 3)
// dBCeBACeB 6 - 7 (1 - 7)
// eBCDBACeB 7 - 4 (1 - 4), 8 - 8, 9 - 9


// abcdefg
// bcdefga
// dcbefga