#include <bits/stdc++.h>
using namespace std;

/*
Bracket matching algorithm using a stack.
If opening bracket ([{ detected, insert to the top of the stack.
If closing bracket )]} detected, check if matches the most recent opening bracket (i.e. the one at the top of the stack).
Finally, check that the number of opening and closing brackets are the same.
*/

int main() {
    string err = "Invalid sequence!";
    string s; cin >> s;
    int l = s.length();
    stack<int> br;
    br.push(0);

    for (int i=0; i<l; i++) {
        switch(s[i]) {
            case '(':
                br.push(1);
            break;
            case '[':
                br.push(2);
            break;
            case '{':
                br.push(3);
            break;
            case ')':
                if (br.top() == 1) {
                    br.pop();
                } else {
                    cout << err << '\n';
                    return 0;
                }
            break;
            case ']':
                if (br.top() == 2) {
                    br.pop();
                } else {
                    cout << err << '\n';
                    return 0;
                }
            break;
            case '}':
                if (br.top() == 3) {
                    br.pop();
                } else {
                    cout << err << '\n';
                    return 0;
                }
            break;
        }
    }

    if (br.size() == 1) {
        cout << "Valid sequence!" << '\n';
    } else {
        cout << err << '\n';
    }
    return 0;
}