#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;
    int n;
    vector<vector<int>> memo = vector<vector<int>>(20, vector<int>(20, -1));;

    bool isMatch(string s, string p) {
        m = s.length();
        n = p.length();

        return parse(s, p, 0, 0);
        // store 0 for false, 1 for true
    }

    int parse(string& s, string& p, int a, int b) {
        if (b == n) { 
            if (a == m) return 1; 
            return 0;
        }
        int &ans = memo[a][b];
        if (ans >= 0) return ans;

        bool curr = false;
        bool match = (a < m && ((s[a] == p[b]) || (p[b] == '.')));

        if (b < n-1 && p[b+1] == '*') {
            ans = parse(s, p, a, b+2) || (match && parse(s, p, a+1, b));
        } else {
            ans = (match && parse(s, p, a+1, b+1));
        }

        return ans;
    }
};