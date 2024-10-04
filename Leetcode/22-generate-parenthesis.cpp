#include <sstream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* It suffices to use the property that any valid combination must be of the form (S)T, where
    S, T are also valid combinations. */
    /* Alternatively, we can also recursively build up valid sequences. */

    vector<vector<string>> memo;
    vector<string> ans;

    vector<string> generateParenthesis(int n, int sol = 0) {
        if (sol) {
            memo = vector<vector<string>>(9, vector<string>());
            memo[0].emplace_back("");
            memo[1].emplace_back("()");
            return rec(n);
        }
        rec2(n, n, "");
        return ans;
    }

    vector<string> rec(int n) {
        if (!memo[n].empty()) {
            return memo[n];
        }
        vector<string> res = memo[n];

        for (int i=0; i<n; i++) {
            vector<string> va = rec(i);
            vector<string> vb = rec(n-1-i);
            for (auto a : va) {
                for (auto b : vb) {
                    ostringstream os;
                    os << "(" << a << ")" << b;
                    res.emplace_back(os.str());
                }
            }
        }

        return res;
    }

    void rec2(int left, int right, string s) {
        if (left) {
            rec2(left-1, right, s + "(");
            if (left < right) { rec2(left, right-1, s + ")"); }
        } else {
            if (right) { ans.emplace_back(s + string(right, ')')); } 
            else { ans.emplace_back(s); }
        }
    }
};