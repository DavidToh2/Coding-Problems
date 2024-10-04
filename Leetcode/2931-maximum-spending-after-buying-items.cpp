#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    list<int> li;
    int m, n, s = 0;
    priority_queue<int, vector<int>> pq;

    ll maxSpending(vector<vector<int>>& values) {
        m = values.size();
        n = values[0].size();
        for (int j=0; j<n; j++) {
            li.emplace_back(values[0][j]);
        }
        for (int i=1; i<m; i++) {
            merge(values[i]);
        }

        // for (auto c : li) cout << c << " ";

        ll sum = 0; ll k = m*n;
        for (auto c : li) {
            sum += ll(c) * k;
            k--;
        }
        return sum;
    }

    void merge(vector<int>& a) {
        int j=0;
        for (auto it=li.begin(); it!=li.end(); it++) {
            while (j < n && *it < a[j]) {
                li.emplace(it, a[j]); j++;
            }
        }
        for (int j1=j; j1<n; j1++) li.emplace_back(a[j1]);
        s += n;
    }
    
    ll maxSpending2(vector<vector<int>>& values) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        m = values.size();
        n = values[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                pq.push(values[i][j]);
            }
        }

        // For this part we only need to extract the maximum every time. Hence it is better to
        // use a max-heap, which lets us avoid the costly merging of the linked-list implementation.
        // Note: directly sorting and iterating through a vector may be faster.
        ll sum = 0; int k = m*n;
        while (!pq.empty()) {
            sum += ll(pq.top()) * k;
            pq.pop();
            k--;
        }
        return sum;
    }
};