#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; string o;
    int i=0;
    getline(cin, s);
    int l=s.length();

    while (i<l) {
        char a = s[i]; char b; char c;
        if (i<l-2) {
            b = s[i+1];
            c = s[i+2];
            if (a != b && b != c && c != a) {
                o.append("C");
                i+=3;
                continue;
            }
        }
        switch(a) {
            case 'R':
                o.append("S");
            break;
            case 'B':
                o.append("K");
            break;
            case 'L':
                o.append("H");
            break;
        }
        i++;
    }
    cout << o << '\n';
}