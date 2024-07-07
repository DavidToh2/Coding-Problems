#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, vector<int>>> count;
    // count[i].first = index
    // count[i].second[0] = overall effect
    // count[i].second[1] = max increase
    // count[i].second[2] = min decrease
    int total = 0;

    for (int i=1; i<=n; i++) {
        string s; cin >> s;
        int l = s.length();
        int c = 0, min = 0, max = 0;
        for (int j=0; j<l; j++) {
            if (s[j] == '(') {
                c++;
                if (c > max) {
                    max++;
                }
            } else if (s[j] == ')') {
                c--;
                if (c < min) {
                    min--;
                }
            }
        }

        vector<int> v = {c, max, min};
        count.emplace_back(make_pair(i, v));
        total += c;
    }

    // cout << "Unsorted:\n";
    // for (int i=0; i<n; i++) {
    //     cout << count[i].first << " " << count[i].second[0] << " " << count[i].second[1] << " " << count[i].second[2] << '\n';
    // }

    if (total != 0) {
        cout << "impossible";
        return 0;
    }

    // sort by min decrease

    sort(count.begin(), count.end(), [](auto &left, auto &right) {
        if (left.second[2] > right.second[2]) {
            return true;
        } else if (left.second[2] == right.second[2]) {
            if (left.second[0] > right.second[0]) {
                return true;
            }
        }
        return false;
    });

    cout << "Sorted:\n";
    for (int i=0; i<n; i++) {
        cout << count[i].first << " " << count[i].second[0] << " " << count[i].second[1] << " " << count[i].second[2] << '\n';
    }

    int curr = 0;
    bool possible = true;
    for (int i=0; i<n; i++) {
        if (curr + count[i].second[2] < 0) {
            possible = false;
            break;
        } else {
            curr += count[i].second[0];
            // cout << "Current: " << curr << " Item: " << count[i].first << '\n';
        }
    }

    if (possible) {
        for (int i=0; i<n; i++) {
            cout << count[i].first << '\n';
        }
    } else {
        cout << "impossible";
    }
    
}