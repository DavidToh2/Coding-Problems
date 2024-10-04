#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void print_vec(vector<ll> v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%lli ", *it);
    }
    printf("\n");
}

int main() {
    int t; scanf("%i", &t);
    for (int i=0; i<t; i++) {
        ll n; scanf("%lli", &n);
        vector<ll> v; ll k; ll max = 0; ll sum = 0;
        unordered_map<ll, int> s;
        for (int j=0; j<n; j++) {
            scanf("%lli", &k);
            if (s.count(k) == 1 && k > max) {
                max = k;
            } else {
                s[k] = 1;
            }
            sum += k;
            v.emplace_back(max);
        }
        // print_vec(v);
        vector<ll> v2; ll curr = 0; bool b = false;
        for (int j=1; j<n; j++) {
            if (v[j] != v[j-1]) {
                b = true;
            } else {
                if (b) { curr = v[j]; b = false; }
            }
            v2.emplace_back(curr);
            sum += v[j];
        }
        // print_vec(v2);
        for (int j=0; j<n-1; j++) {
            sum += (v2[j] * (n-1-j));
        }
        printf("%lli\n", sum);
    }
}