#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%i", &n);
    for (int i=0; i<n; i++) {
        int k; scanf("%i", &k);
        int buf; scanf("%i", &buf);
        int a; scanf("%i", &a);
        if (a != buf + 1) {
            int b; scanf("%i", &b);
            if (b == a+1) {
                printf("1\n");
            } else if (b == buf+1) {
                printf("2\n");
            }
        } else {
            buf = a;
            for (int j=3; j<=k; j++) {
                scanf("%i", &a);
                if (buf + 1 != a) {
                    printf("%i\n", j);
                    break;
                } else {
                    buf = a;
                }
            }
        }
        char c;
        while (scanf("%c", &c) != EOF) {
            if (c == '\n') break;
        }
    }
}