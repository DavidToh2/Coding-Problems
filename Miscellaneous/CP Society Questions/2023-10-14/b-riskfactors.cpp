#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; int K; int L;
    cin >> N >> K >> L;
    string s; cin >> s;
    string risk; cin >> risk;
    vector<int> n;

    for (int i=0; i<N; i++) {
        bool isRisk = false;
        for (int j=0; j<L; j++) {
            if (s[i] == risk[j]) {
                isRisk = true;
            }
        }

        if (isRisk) {
            n.emplace_back(i);
        }
    }

    // cout << "The positions of the risk letters are: ";
    // for (int i=0; i<n.size(); i++) {
    //     cout << n[i] << " ";
    // }
    // cout << '\n';

    int count = 0;
    if (n.size() < K) {
        cout << "0";
    } else {
        int s = n.size();
        for (int i=0; i<=s-K; i++) {
            // cout << "Performing case i = " << i << " of " << s-K << " where s = " << s << " and K = " << K << "\n";
            if (s == K) {
                count += (n[i] + 1) * (N - n[i+K-1]);
                // cout << "Case 1 ";
            } else if (i == 0) {
                count += (n[i] + 1) * (n[i+K] - n[i+K-1]);
                // cout << "Case 2 ";
            } else if (i == s-K) {
                count += (n[i] - n[i-1]) * (N - n[i+K-1]);
                // cout << "Case 3 ";
            } else {
                count += (n[i] - n[i-1]) * (n[i+K] - n[i+K-1]);
                // cout << "Case 4 ";
            }
            //cout << count << '\n';
        }
        cout << count;
    }

}