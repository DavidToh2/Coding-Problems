#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t; scanf("%i", &t);
    for (int i=0; i<t; i++) {
        ll n, k, x; scanf("%lld %lld %lld", &n, &k, &x);
        ll a = k * (k+1) / 2;
        ll b = a + k * (n-k);
        if (a <= x && x <= b) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}