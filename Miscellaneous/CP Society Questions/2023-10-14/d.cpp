#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t >> n;
    vector<int> A(n, 0);
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }
    int q; cin >> q;
    for (int i=0; i<q; i++) {
        int l, k, k2;
        cin >> l >> k;
        
        // Note that the sequence c[x] = a[l] & a[l+1] & ... & a[x] is monotone decreasing. Hence, a binary search suffices

        bool done = false;
        if (A[l-1] >= k) {
            done = true;
        }

        vector<int> B(n+1-l, 0);
        B[0] = A[l-1];
        for (int j=1; )

        int r = (n + l) / 2 - 1, r0 = r - l;
        while (!done) {
            int a = A[l-1];
            for (int j=l; j<l+r; j++) {
                a &= A[j];
            }
            if ()
        }
    }
}