#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int i=0; i<t; i++) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int L[k]; int R[k];     // both indexed at 0
        for (int j=0; j<k; j++) {
            cin >> L[j]; L[j]--;
        }
        for (int j=0; j<k; j++) {
            cin >> R[j]; R[j]--;
        }
        int q; cin >> q;
        int count[n] = {0};

        for (int j=0; j<q; j++) {
            int x; cin >> x; count[x-1]++;      // indexed at 0
        }

        for (int j=0; j<k; j++) {
            int y = 0;
            for (int l=L[j]; l<=(L[j]+R[j])/2; l++) {
                y += (count[l] + count[L[j]+R[j]-l]);
                if (y & 1) {
                    swap(s[l], s[L[j]+R[j]-l]);
                }
            }
        }

        cout << s << "\n";
    }
}