#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%i", &n);
    for (int i=0; i<n; i++) {
        int m; int x; int y; scanf("%i %i %i", &m, &x, &y);
        for (int j=0; j<y; j++) {
            if ((y-j) & 1 == 1) {
                printf("1 ");
            } else {
                printf("-1 ");
            }
        }
        for (int j=y; j<x; j++) {
            printf("1 ");
        }
        for (int j=x; j<m; j++) {
            if ((j-x) & 1 == 1) {
                printf("1 ");
            } else {
                printf("-1 ");
            }
        }
        printf("\n");
    }
}

/**
 * (10, 4, 7): -1 1 -1 1 1 1 1 -1 1 -1
 * (10, 5, 6): 1 -1 1 -1 1 1 -1 1 -1 1
 */