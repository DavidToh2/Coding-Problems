#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; int k;
    scanf("%i %i", &n, &k);

    int a;
    queue<int> activeRequests;
    int c, l, max = 0;
    
    for (int i=0; i<n; i++) {
        scanf("%i", &a);
        activeRequests.push(a);
        while ((c = activeRequests.front()) <= a - 1000) {
            activeRequests.pop();
        }
        l = activeRequests.size();
        if (l > max) {
            max = l;
        }
    }

    int res = max / k;
    if (max % k == 0) {
        printf("%i", res);
    } else {
        printf("%i", res + 1);
    }
}