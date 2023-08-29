#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const ll mod = 1020340567;
const ll N = 1e7;
vector<ll> F;
int main() {

  F.assign(N + 1, 0);
  F[1] = 2;

  ll twopowi = 1; // 1 * 2
  ll ans = 2;
  
  for (int i = 2; i <= N; i++) {
    twopowi <<= 1LL; // twopowi *= 2
    twopowi %= mod;
    F[i] = (F[i] + twopowi - 2) % mod;

    for (ll j = 2 * i; j <= N; j += i) {
      F[j] = (F[j] - F[i]) % mod;
    }
    ans = (ans + F[i]) % mod;
  }
  cout << (ans + mod) % mod << endl;

  return 0;
}