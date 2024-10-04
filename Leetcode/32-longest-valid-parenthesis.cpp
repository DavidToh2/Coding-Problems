#include <bits/stdc++.h>
using namespace std;

/*
One solution makes use of the following two observations: on a linear pass from left to right,
- Any additional ) automatically splits the valid parenthesis strings on the left from those on the right;
- Any remaining ('s in the stack at the end of the process also delimit valid parenthesis strings between them.

Alternate DP solution: Every valid substring is of the form (S)T. Thus, for each left bracket ( at position k, 
we may attempt to find the longest valid substring beginning at that position, which we call f[k]. To do so,
- first find f[k+1];
- if this is followed by a (, then by the maximality of f[k+1], this cannot have a matching ), so
f[k] does not exist and is also a lone (;
- otherwise, if it's followed by a ), then f[k] is comprised of a (, followed by f[k+1], followed 
by ), followed by f[k+2+f[k+1]] provided this character is also a (.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        deque<int> st;
        vector<int> v = vector<int>({ -1 });
        int l = s.length(), i = 0;
        while (i < l) {
            if (s[i] == '(') {
                st.push_back(i);
            } else {
                if (st.empty()) { v.emplace_back(i); } 
                else { st.pop_back(); }
            }
            i++;
        }
        st.push_back(i);
        while (!st.empty()) { v.emplace_back(st.front()); st.pop_front(); }

        int m = 0, a = 0;
        for (int j=0; j<v.size()-1; j++) {
            a = v[j+1] - v[j] - 1;
            m = (m < a) ? a : m;
        }

        return m;
    }

    int longestValidParentheses2(string s) {

        int l = s.length();
        if (!l) return 0;
        vector<int> v = vector<int>(l+1, 0);
        for (int i = l-2; i >= 0; i--) {
            if (s[i] == '(') {
                int c = v[i+1];
                if (i+c == l-1) { v[i] = 0; }
                else if (s[i+c+1] == '(') { v[i] = 0; }
                else { v[i] = 2 + v[i+1] + v[i+v[i+1]+2]; }
            }
        }

        return *max_element(v.begin(), v.end());
    }
};