#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%i", &t);
    int n; int k;
    for (int i=0; i<t; i++) {
        int b;
        bool t = false;
        scanf("%i %i", &n, &k);
        for (int j=0; j<n; j++) {
            scanf("%i", &b);
            if (b == k && !t) {
                t = true;
                printf("YES\n");
            }
        }
        if (!t) {
            printf("NO\n");
        }
    }
}