#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%i", &n);
    while (n--) {
        int p; int r; int f; int k = 0;
        scanf("%i %i %i", &p, &r, &f);
        while (p <= f) {
            // Apparently dividing f by r is faster than multiplying p by r.
            // The latter led to a TLE.
            f /= r;
            k++;
        }
        printf("%i\n", k);
    }
}