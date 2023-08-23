#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; string n1;
    getline(cin, n1); n = stoi(n1);
    for (int j=1; j<=n; j++) {
        printf("Case %i: ", j);
        string s, t;
        getline(cin, s); getline(cin, t);
        int l = s.length();

        int a = 0, a1 = 0, b = 0, b1 = 0;
        // s/t
        // a = 1/0, a1 = ?/0, b = 0/1, b1 = ?/1
        
        for (int i=0; i<l; i++) {
            switch(s[i]) {
                case '?':
                    if (t[i] == '0') a1++;
                    if (t[i] == '1') b1++;
                break;
                case '0':
                    if (t[i] == '1') b++;
                break;
                case '1':
                    if (t[i] == '0') a++;
                break;
            }
        }
        // printf("%i %i %i %i\n", a, a1, b, b1);
        if (b+b1 < a) {
            printf("-1\n");
        } else {
            if (a < b) {
                printf("%i\n", b + a1 + b1);
            } else {
                printf("%i\n", a + a1 + b1);
            }
        }
    }
}