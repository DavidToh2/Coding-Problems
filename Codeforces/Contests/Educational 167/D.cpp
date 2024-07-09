#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; int m; scanf("%i %i", &n, &m);
    vector<ll> A(n, 0);
    vector<ll> B(n, 0);
    vector<ll> C(m, 0);
    for (int i=0; i<n; i++) { scanf("%lli", &A[i]); }
    for (int i=0; i<n; i++) { scanf("%lli", &B[i]); }
    for (int i=0; i<m; i++) { scanf("%lli", &C[i]); }
    map<int, int> D;
    for (int i=0; i<n; i++) {
        ll t = A[i] - B[i];
        if (D.count(t) > 0) {
            if (D[t] > A[i]) D[t] = A[i];
        } else {
            D[t] = A[i];
        }
    }
    auto it = D.begin();
    while (it != prev(D.end())) {
        if (it->second < (next(it))->second) D.erase(next(it));
        else ++it;
    }

    vector<int> memo(1000000, 0);
    ll res = 0;
    for (int j=0; j<m; j++) {
        ll ingots = C[j], part_res = 0ll;
        auto it = D.begin();
        vector<pair<ll, ll>> T;
        while (it != D.end()) {
            ll cost = it->first, threshold = it->second;
            if (ingots < threshold) {
                if (ingots < cost) break;
                it++;
            } else {
                ll r = (ingots - threshold) / cost + 1;
                T.emplace_back(pair<ll, ll>(2 * r, ingots));
                ingots -= (r * cost);
                if (memo[ingots] != 0) {
                    part_res += memo[ingots];
                    break;
                }
                it++;
            }
        }
        ll l = T.size();
        if (l > 0) {
            while (l > 1) {
                l--;
                auto p = T[l];
                part_res += p.first;
                memo[p.second] = part_res;
            }
            res += (part_res + T[0].first);
        }
    }
    printf("%lli", res);

}