#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    vector<int> nos;
    vector<int> max;
    vector<int> min;

    scanf("%i", &n);
    for (int i=0; i<n; i++) {
        scanf("%i", &c);
        nos.emplace_back(c);
    }
    max.emplace_back(nos[0]);
    min.emplace_back(nos[n-1]);
    for (int i=1; i<n; i++) {
        if (nos[i] > max[i-1]) {
            max.emplace_back(nos[i]);
        } else {
            max.emplace_back(max[i-1]);
        }
        if (nos[n-1-i] < min[i-1]) {
            min.emplace_back(nos[n-1-i]);
        } else {
            min.emplace_back(min[i-1]);
        }
    }

    int count = 0;
    for (int i=0; i<n; i++) {
        if (nos[i] == max[i] && nos[i] == min[n-1-i]) {
            count++;
        }
    }

    printf("%i", count);
}