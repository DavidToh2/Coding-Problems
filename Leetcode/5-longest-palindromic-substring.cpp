#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), m = 0; 
        int ans[2] = {0, 0};
        for (int i = 0; i < n; i++) {

            int l = i, r = i;
            while ((l >= 0) && (r < n) && (s[l] == s[r])) {
                l--; r++;
            }
            if (r+1-l > m) { m = r+1-l; ans[0] = l+1; ans[1] = r-1; }

            if ((i < n-1) && (s[i] == s[i+1])) {
                l = i; r = i+1;
                while (l >= 0 && r < n && s[l] == s[r]) {
                    l--; r++; 
                }
                if (r+1-l > m) { m = r+1-l; ans[0] = l+1; ans[1] = r-1; }
            }
        }
        return s.substr(ans[0], ans[1] + 1 - ans[0]);
    }
};