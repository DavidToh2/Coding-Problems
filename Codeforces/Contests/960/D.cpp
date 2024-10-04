#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; scanf("%i", &t);
    for (int i=0; i<t; i++) {
        int n; scanf("%i", &n);
        int k; bool duo = false; int sum = 0; int c = 0;
        vector<int> v;
        for (int j=0; j<n; j++) {
            scanf("%i", &k); v.emplace_back(k);
        }
        int j = 0;
        while (j < n) {
            k = v[j];
            if (k <= 2) {
                if (duo) {
                    if ((c & 1 == 1) && k > 0) {
                        if (j<n-1) {
                            if (v[j+1] <= 2) { j++; }
                            sum += (c+2);
                        } else { sum += (c+2); }
                    } else {
                        sum += (c+1);
                    }
                    duo = false;
                    c = 0;
                } else if (k > 0) {
                    duo = true; 
                }
            } else if (k <= 4) {
                if (duo) { c++; }
                else { sum += 1; }
            } else {
                if (duo) {
                    duo = false;
                    sum += (c+2);
                    c = 0;
                } else { sum += 1; }
            }
            j++;
            // printf("%i ", sum);
        }
        if (duo) { sum += (c+1); }
        printf("%i\n", sum);
    }
}