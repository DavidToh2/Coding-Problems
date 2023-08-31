#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N = 1e16;
    ll d = 0;
    ll c = 4*N - 163;
    ll y = 1;
    ll ans = 0;

    ll red = 0ll;

    do {
        d = sqrt(c);
        red += d/2;
        if (d % 2 == 1 && y % 2 == 1) {
            red += 1ll;
        }
        y++;
        c = 4*N - 163*y*y;
    } while (c > 0);

    ll blue = (ll) sqrt(4*N) / 2;
    ll green = (ll) sqrt(4*N / 163) / 2;

    printf("Answer: %lld", 4*red + 2*blue + 2*green);
}