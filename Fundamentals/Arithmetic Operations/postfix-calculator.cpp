#include <bits/stdc++.h>
using namespace std;

/*
Postfix notation is a method of writing arithmetic statements where the arithmetic operator comes after the numbers.
For example, 2 3 * would translate to 2 * 3 = 6 in infix notation (i.e. standard arithmetic).
More complicated statements will have operators "collapse" to the right, disregarding conventional BODMAS rules.
For example, to evaluate 3 4 5 + *, we would first evaluate 4 5 + giving 9, then evaluate 3 9 * giving 27.

In this way, postfix arithmetic can be efficiently implemented using stacks.

We implement a postfix operator that takes in numbers and operators, separated by spaces.
*/

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
    string s0;
    stack<int> s;
    while(getline(cin, s0, ' ')) {
        if (isnumeric(s0)) {
            s.push(stoi(s0));
        } else {
            int a, b;
            if (s.size() < 2) {
                cout << "Error! Check your inputs!" << '\n';
                return 1;
            }
            switch(s0[0]) {
                case '+':
                    a = s.top();
                    s.pop();
                    b = s.top();
                    s.pop();
                    s.push(b+a);
                break;
                case '-':
                    a = s.top();
                    s.pop();
                    b = s.top();
                    s.pop();
                    s.push(b-a);
                break;
                case '*':
                    a = s.top();
                    s.pop();
                    b = s.top();
                    s.pop();
                    s.push(b*a);
                break;
                case '/':
                    a = s.top();
                    s.pop();
                    b = s.top();
                    s.pop();
                    s.push((int)(b/a));
                break;
            }
        }
    }
    if (s.size() != 1) {
        cout << "Error! Check your inputs!" << '\n';
    } else {
        cout << s.top() << '\n';
    }

}