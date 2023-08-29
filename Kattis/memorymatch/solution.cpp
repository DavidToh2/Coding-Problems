#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<string, set<int>> cards;

    for (int i=0; i<k; i++) {
        int a, b; string a1, b1;
        cin >> a >> b >> a1 >> b1;
        cards[a1].emplace(a);
        cards[b1].emplace(b);
        if (a1 == b1) {
            n -= 2;
            cards.erase(a1);
        }
    }

    // s: number of symbols for which both cards have already appeared (known as pairs)
    // t: number of symbols for which only one card has appeared (known as singletons)
    int s = 0, t = 0;
    for (auto j : cards) {
        if (j.second.size() == 2) {
            s++;
        } else if (j.second.size() == 1) {
            t++;
        }
    }

    // Edge case 1: if the number of unflipped cards is less than the number of singleton flipped cards,
    // then we can match all the symbols. This is because each unflipped card must correspond to a singleton flipped card.
    // Edge case 2: if all pairs save one have already been flipped, then we can match all the symbols.
    if (2*s + 2*t >= n || 2*s >= n-2) {
        printf("%i", n/2);
    } else {
        printf("%i", s);
    }

}