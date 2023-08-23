#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%i", &n);
    int m; int k = 0; int a;
    scanf("%i", &m);
    for (int i=1; i<n; i++) {
        scanf("%i", &a);
        if (a<m) {
            m = a;
            k = i;
        }
    }
    printf("%i", k);
}