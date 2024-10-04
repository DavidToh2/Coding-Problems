#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;
    int n;
    vector<vector<int>> memo;

    bool isMatch(string s, string p) {
        m = s.length(); n = p.length();
        memo = vector<vector<int>>(m+1, vector<int>(n+1, -1));
        if (!n && m) return false;
        dp(s, p, 0, 0);
        return memo[0][0];
    }

    int dp(string& s, string& p, int a, int b) {
        // The crucial decision in the DP is whether to consume a character or a regex.
        if (a == m && b == n) return 1;
        if (b == n) return 0;
        if (memo[a][b] >= 0) return memo[a][b];

        int res = 0;
        if (p[b] == '*') {
            if (b == n-1) res = 1;
            else if (a == m) res = (p[b+1] == '*') && dp(s, p, a, b+1);
            else res = dp(s, p, a+1, b) || dp(s, p, a, b+1);
        } else {
            if (a == m) res = 0;
            else res = ((s[a] == p[b]) || (p[b] == '?')) && dp(s, p, a+1, b+1);
        }
        memo[a][b] = res;
        // cout << a << b << p[b] << res << memo[a][b];
        return res;
    }
};