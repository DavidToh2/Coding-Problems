#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%i", &n);
    for (int i=0; i<n; i++) {
        int k; scanf("%i", &k);
        for (int j=0; j<k; j++) {
            printf("%i ", j+7);
        }
        printf("\n");
    }
}