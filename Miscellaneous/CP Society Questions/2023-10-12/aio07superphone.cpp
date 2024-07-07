#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("phonein.txt");
    ofstream cout("phoneout.txt");

    int n; cin >> n;
    vector<int> L(n-1, 0);
    vector<int> C(n, 0);
    vector<int> R(n-1, 0);

    for (int i=0; i<n-1; i++) {
        cin >> L[i] >> C[i] >> R[i];
    }
    cin >> C[n-1];

    vector<int> Ldp(n, 0);
    vector<int> Rdp(n, 0);

    Rdp[n-1] = 0; Ldp[n-1] = C[n-1];
    for (int i=n-2; i>=0; i--) {
        Ldp[i] = min(Rdp[i+1] + L[i], Ldp[i+1] + C[i] + R[i]);
        Rdp[i] = min(Ldp[i+1] + R[i], Rdp[i+1] + C[i] + L[i]);
    }

    cout << Ldp[0];
}