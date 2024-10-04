#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%i", &n);
    for (int i=0; i<n; i++) {
        int m; scanf("%i", &m);
        map<int, int> k;
        for (int j=0; j<m; j++) {
            int l; scanf("%i", &l);
            if (k.count(l)) {
                k[l] += 1;
            } else {
                k[l] = 1;
            }
        }
        bool done = false;
        for (auto p : k) {
            if (p.second % 2 != 0) {
                done = true;
                break;
            }
        }
        if (done) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}