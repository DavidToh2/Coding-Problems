#pragma GCC optimise("Ofast")
#pragma GCC optimise("unroll-loops")

#include <bits/stdc++.h>
#include <chrono>

using namespace std;

typedef long long ll;

ll C = 25214903917;
ll d = 11;
ll t16 = 0b10000000000000000;
ll t18 = 0b1000000000000000000;
ll t32 = 0b100000000000000000000000000000000;
ll t48 = 0b1000000000000000000000000000000000000000000000000;
ll C18 = C % t18;
ll C32 = C % t32;

struct v16 {
    ll next;
    ll overflow;
};
vector<v16> v16v(t16);

void print_vector(vector<ll> &v) {
    int l = v.size();
    for (int i=0; i<l; i++) {
        printf("%lld ", v[i]);
    }
    printf("\n");
}

ll f(ll n) {
    ll ans = ((C*n + d) % t48 + t48) % t48;
    return ans;
}

void solution_part_2() {
    ll a = 144933752257087, a1 = f(a), a2 = (a1 - a) % t48;
    ll b = 160163661474491, b1 = f(b), b2 = (b1 - b) % t48;

    // ll a2 = 99607973670047;
    // ll b2 = 151992572250351;

    // We need to calculate the number of copies of C that is to be multiplied to a2 before we get b2 (mod 2^48).

    vector<ll> ordC, powC;
    ll C482 = C, p2 = 1;
    int e = 0;
    for (int i=1; i<49; i++) {
        p2 *= 2;
        // printf("%lld\n", (C482 + p2) % p2);
        while ((C482 + p2) % p2 != 1) {
            C482 = ((C482 * C482) % t48 + t48) % t48;
            e++;
        }
        printf("The order of %lld mod %lld is 2^%i and is satisfied by %lld.\n", C, p2, e, C482);
        powC.emplace_back(C482);
        ordC.emplace_back(1ll << e);
    }

    print_vector(ordC);
    print_vector(powC);

    printf("Starting order computation...\n");

    ll counter = 0, C1 = 1;
    p2 = 2;
    ll a3 = a2;
    for (int i=2; i<49; i++) {
        p2 *= 2;
        printf("Target: %lld mod %lld = 2^%i\n", ((b2 % p2) + p2) % p2, p2, i);
        printf("Current: %lld mod %lld\n", ((a3 % p2) + p2) % p2, p2);
        while (((a3 % p2) + p2) % p2 != ((b2 % p2) + p2) % p2) {
            a3 = ((a3 * powC[i-2]) % t48 + t48) % t48;
            printf("Multiplying by %lld\n", powC[i-2]);
            counter += ordC[i-2];
            // printf("Current: %lld is %lld mod %lld\n", a3, ((a3 % p2) + p2) % p2, p2);
        }
    }

    printf("counter = %lld\n", counter);
}

void solution_part_1() {
    // string s = "bQYicNGCY";     // 130 microseconds
    // string s = "EULERcats";     // 81.2ms
    // string s = "PuzzleOne";     // 147.6ms, x0 = 2211513553, y0 = 47679 -> a0 = 144933752257087
    string s = "LuckyText";     // 172.6ms, x0 = 2443903525, y0 = 60091 -> a0 = 160163661474491
    
    vector<int> sv, sv4;
    for (int i=0; i<9; i++) {
        ll c = ll(int(s[i]));
        if (c >= 97) {
            sv.emplace_back(c - 97);
            sv4.emplace_back((c - 97) % 4);
        } else {
            sv.emplace_back(c - 39);
            sv4.emplace_back((c - 39) % 4);
        }
        // printf("%i ", sv.back());
    }

    ll seed = -1;
    vector<ll> seedoverflow;
    for (ll i=0; i<t16; i++) {
        ll j = sv4[0]*t16 + i;
        ll j4;
        bool found = true;
        for (int k=1; k<9; k++) {
            j = (C18 * j + 11 + t18) % t18;
            j4 = j >> 16;
            if (j4 != sv4[k]) {
                found = false;
                break;
            }
        }
        if (found) {
            seed = i;
            printf("Found seed: last 16 bits are %lld\n", seed);
            for (int k=0; k<8; k++) {
                ll s = f(seed);
                seed = s % t16;
                seedoverflow.emplace_back(s >> 16);
            }
            break;
        }
    }

    if (seed == -1) {
        printf("Error! Seed not found\n");
        return;
    }

    ll x0 = sv[0];
    while (x0 < t32) {
        ll x1 = x0;
        for (int k=0; k<8; k++) {
            x1 = ((C32 * x1 + seedoverflow[k]) % t32 + t32 ) % t32;
            // printf("%lld %lld %lld %i, ", seedoverflow[k], x1, x1 % 52, sv[k+1]);
            if (x1 % 52 != sv[k+1]) {
                break;
            }
            if (k == 7) {
                printf("String found! The first 32 bits are %lld\n", x0);
                return;
            }
        }
        x0 += 52;
    }

    printf("No string found. Check your code!\n");
}

void solution_old() {

    string s = "bQYicNGCY";     // This string has starting value 123456, so should give x0 = 1, y0 = 59720
    // string s = "EULERcats";     // This string should give a0 = 78580612777175, so x0 = 1199044994, y0 = 50391
    // string s = "PuzzleOne";     // x0 = 2211513553, y0 = 47679, duration = 8714.695s = 2.42h
    vector<int> sv;
    for (int i=0; i<9; i++) {
        ll c = ll(int(s[i]));
        if (c >= 97) {
            sv.emplace_back(c - 97);
        } else {
            sv.emplace_back(c - 39);
        }
        // printf("%i ", sv.back());
    }

    for (ll i=0; i<t16; i++) {
        ll j = f(i);
        v16v[i].next = (j % t16 + t16) % t16;
        v16v[i].overflow = (j >> 16);
    }

    ll x0 = sv[0];
    // vector<ll> x;
    while (x0 < 2) {
        for (ll i=0; i<t16; i++) {
            ll x = x0;
            // x.emplace_back(x0);
            ll j=i;
            for (int k=0; k<8; k++) {
                x = ((C32 * x + v16v[j].overflow) % t32 + t32) % t32;
                j = v16v[j].next;
                // if (i == 57920) {
                //     printf("(%lld %lld %lld %i)\n", v16v[j].overflow, x, (x % 52), sv[k+1]);
                // }
                if (x % 52 != sv[k+1]) {
                    break;
                }
                if (k == 7) {
                    printf("String found! The relevant values are x0=%lld, y0=%lld\n", x0, i);
                    return;
                }
            }
            // printf("Analyzing number %lld: ", i);
            // print_vector(x);
            // x.clear();
        }
        x0 += 52;
        if (x0 % 100000 == 1) {
            printf("Now analyzing x0=%lld\n", x0);
        }
    }
}

int main(int argc, char* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    auto start = chrono::high_resolution_clock::now();

    solution_part_2();
    
    auto end = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << endl << "Your program took " << dur.count() << " microseconds!" << '\n' << '\n';
    return 0;
}