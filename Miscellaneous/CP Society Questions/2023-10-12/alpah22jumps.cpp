#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> v(N, 0);

    for (int i=0; i<N; i++) {
        cin >> v[i];
    }

    int zerosum = 0, onesum = 0;
    if (v[0]) {
        onesum++;
    } else {
        zerosum++;
    }

    for (int i=1; i<N; i++) {
        if (v[i]) {
            // if (!zerosum) {
            //     onesum++;
            // }
            onesum = ((zerosum + onesum ) % 1000000007 + 1000000007) % 1000000007;
        } else {
            // if (!onesum) {
            //     zerosum++;
            // }
            zerosum = ((zerosum + onesum) % 1000000007 + 1000000007) % 1000000007;
        }
        // cout << zerosum << " " << onesum << '\n';
    }

    if (v[N-1]) {
        cout << (zerosum % 1000000007);
    } else {
        cout << (onesum % 1000000007);
    }
}