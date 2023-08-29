#include <bits/stdc++.h>
using namespace std;

bool isnumeric(string &s) {
    bool ret = true;
    for (int i=0; i<s.length(); i++) {
        if (!isdigit(s[i])) {
            ret = false;
        }
    }
    return ret;
}

int main() {
    string s;
    stack<string> stackop;
    queue<string> postfix;
    stackop.push("A");

    while (getline(cin, s, ' ')) {
        if (isnumeric(s)) {
            postfix.push(s);
        } else {
            if (s.length() != 1) {
                cout << "Non-numeric string of invalid length detected. Check your inputs!" << '\n';
            } else {
                string c = stackop.top();
                switch(s[0]) {
                    case '(':
                        stackop.push(s);
                    break;
                    case ')':
                        while (c != "(" && c != "A") {
                            stackop.pop();
                            postfix.push(c);
                            c = stackop.top();
                        }
                        stackop.pop();
                    break;
                    case '+':
                    case '-':
                        while (c != "(" && c != "A") {
                            stackop.pop();
                            postfix.push(c);
                            c = stackop.top();
                        }
                        stackop.push(s);
                    break;
                    case '*':
                    case '/':
                        while (c != "(" && c != "+" && c != "-" && c != "A") {
                            stackop.pop();
                            postfix.push(c);
                            c = stackop.top();
                        }
                        stackop.push(s);
                    break;
                }
            }
        }
    }

    int rem = stackop.size();
    if (rem < 0) {
        cout << "Error in algorithm!" << '\n';
    } else if (rem > 1) {
        for (int i=0; i<rem-1; i++) {
            postfix.push(stackop.top());
            stackop.pop();
        }
    }

    int l = postfix.size();
    for (int i=0; i<l; i++) {
        cout << postfix.front() << " ";
        postfix.pop();
    }
}