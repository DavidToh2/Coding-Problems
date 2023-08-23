#include <bits/stdc++.h>
using namespace std;

int main() {
    string c;
    while (getline(cin, c)) {
        int i = 0;
        if (c == "END") break;
        int l;
        while (c != "1") {
            l = c.length();
            c = to_string(l);
            i++;
        }
        printf("%i\n", i+1);
    }
}