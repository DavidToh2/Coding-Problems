#include <bits/stdc++.h>
using namespace std;

/* The algorithm proceeds in four steps:
1. Identify the maximum element of the array.
2. Identify the largest increasing subsequence of the array, from both ends, up to this maximum.
3. Compute the volume of rainwater directly. */

class Solution {
public:
    int trap(vector<int>& height) {
        int l = height.size(), m = 0, c = 0;
        vector<pair<int, int>> v;
        for (int i=0; i<l; i++) {
            if (height[i] > m) {
                v.emplace_back(pair(m, i-c));
                m = height[i]; c = i;
            }
        }
        int m1 = 0, c1 = l-1;
        for (int j=l-1; j>=c; j--) {
            if (height[j] > m1) {
                v.emplace_back(pair(m1, c1-j));
                m1 = height[j]; c1 = j;
            }
        }
        v.emplace_back(pair(m, c1-c+1));
        // for (auto p : v) {
        //     cout << p.first << " " << p.second << "; ";
        // }

        int res = 0;
        for_each(v.begin(), v.end(), [&](pair<int, int>& p) { res += p.first * p.second; });
        for_each(height.begin(), height.end(), [&](int& k) { res -= k; });

        return res;
    }
};